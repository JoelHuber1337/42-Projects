/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 19:25:08 by johuber           #+#    #+#             */
/*   Updated: 2026/04/24 20:29:26 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("Default") , signGrade(42) , execGrade(42)
{
	isSigned = false;
}

AForm::AForm(std::string name, int signgrade, int execgrade) : name(name) , signGrade(signgrade) , execGrade(execgrade)
{
	isSigned = false;
	if (execgrade < HIGHEST_GRADE || signgrade < HIGHEST_GRADE)
		throw (AForm::GradeTooHighException());
	if (execgrade > LOWEST_GRADE || signgrade > LOWEST_GRADE)
		throw (AForm::GradeTooLowException());
}

AForm::AForm(const AForm &cpy) :name(cpy.name) , signGrade(cpy.signGrade) , execGrade(cpy.execGrade)
{
	*this = cpy;
	isSigned = false;
}

AForm::~AForm() {}

void	AForm::beSigned(Bureaucrat clerk)
{
	if (isSigned == true)
	{
		std::cout << *this << " is already signed! " << clerk << " throws it to the piled of signed documents, no wonder they keep mixing them up...\n";
		return ;
	}
	if (clerk.getGrade() <= signGrade)
	{
		clerk.signForm(this, false);
		isSigned = true;
	}
	else
	{
		clerk.signForm(this, true);
		throw(AForm::GradeTooLowException());
	}
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (!isSigned)
		throw(AForm::NotSigned());
	if (executor.getGrade() > execGrade)
		throw (AForm::LowExec());
	execDoc();
}

int	AForm::getExecGrade() const
{
	return (this->execGrade);
}

int	AForm::getSignGrade() const
{
	return (this->signGrade);
}

std::string	AForm::getName() const
{
	return (this->name);	
}

bool		AForm::getIsSigned() const
{
	return (this->isSigned);
}

AForm&	AForm::operator = (const AForm &cpy)
{
	if (this == &cpy)
		return (*this);
	return (*this);
}

std::ostream&	operator << (std::ostream &out, const AForm &b)
{
	if (b.getIsSigned())
		out << b.getName() << ", Form Signing grade " << b.getSignGrade() << ", Execution grade " << b.getExecGrade() << " and it is signed.";
	else
		out << b.getName() << ", Form Signing grade " << b.getSignGrade() << ", Execution grade " << b.getExecGrade() << " and it is not signed.";
	return (out);
}

const char	*AForm::NotSigned::what() const throw()
{
	return ("This Document cannot be executed, it is not signed");
}

const char	*AForm::LowExec::what() const throw()
{
	return ("Executor's grade is too low to Execute");
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("This Grade is too high");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("This Grade is too low");
}

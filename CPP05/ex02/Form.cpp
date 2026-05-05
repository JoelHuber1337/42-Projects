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

#include "Form.hpp"

Form::Form() : name("Default") , signGrade(42) , execGrade(42)
{
	isSigned = false;
}

Form::Form(std::string name, int signgrade, int execgrade) : name(name) , signGrade(signgrade) , execGrade(execgrade)
{
	isSigned = false;
	if (execgrade < HIGHEST_GRADE || signgrade < HIGHEST_GRADE)
		throw (Form::GradeTooHighException());
	if (execgrade > LOWEST_GRADE || signgrade > LOWEST_GRADE)
		throw (Form::GradeTooLowException());
}

Form::Form(const Form &cpy) :name(cpy.name) , signGrade(cpy.signGrade) , execGrade(cpy.execGrade)
{
	*this = cpy;
	isSigned = false;
}

Form::~Form() {}

void	Form::beSigned(Bureaucrat clerk)
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
		throw(Form::GradeTooLowException());
	}
}

int	Form::getExecGrade() const
{
	return (this->execGrade);
}

int	Form::getSignGrade() const
{
	return (this->signGrade);
}

std::string	Form::getName() const
{
	return (this->name);	
}

bool		Form::getIsSigned() const
{
	return (this->isSigned);
}

Form&	Form::operator = (const Form &cpy)
{
	if (this == &cpy)
		return (*this);
	return (*this);
}

std::ostream&	operator << (std::ostream &out, const Form &b)
{
	if (b.getIsSigned())
		out << b.getName() << ", Form Signing grade " << b.getSignGrade() << ", Execution grade " << b.getExecGrade() << " and it is signed.";
	else
		out << b.getName() << ", Form Signing grade " << b.getSignGrade() << ", Execution grade " << b.getExecGrade() << " and it is not signed.";
	return (out);
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("This Grade is too high\n");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("This Grade is too low\n");
}

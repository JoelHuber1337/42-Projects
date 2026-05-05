/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 19:25:08 by johuber           #+#    #+#             */
/*   Updated: 2026/04/09 19:42:59 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default")
{
	this->grade = 42;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	this->grade = grade;
	if (grade < HIGHEST_GRADE)
		throw (Bureaucrat::GradeTooHighException());
	if (grade > LOWEST_GRADE)
		throw (Bureaucrat::GradeTooLowException());
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy) :name(cpy.name)
{
	this->grade = cpy.grade;
	*this = cpy;
}

Bureaucrat::~Bureaucrat() {}

int	Bureaucrat::getGrade() const
{
	return (this->grade);
}

std::string	Bureaucrat::getName() const
{
	return (this->name);	
}

Bureaucrat&	Bureaucrat::operator = (const Bureaucrat &cpy)
{
	if (this == &cpy)
		return (*this);
	this->grade = cpy.grade;
	return (*this);
}

void	Bureaucrat::incrementGrade(int plus)
{
	if (grade - plus < HIGHEST_GRADE)
		throw (Bureaucrat::GradeTooHighException());
	if (grade - plus > LOWEST_GRADE)
		throw (Bureaucrat::GradeTooLowException());
	grade -= plus;
}

void	Bureaucrat::decrementGrade(int minus)
{
	if (grade + minus < HIGHEST_GRADE)
		throw (Bureaucrat::GradeTooHighException());
	if (grade + minus > LOWEST_GRADE)
		throw (Bureaucrat::GradeTooLowException());
	grade += minus;
}

std::ostream&	operator << (std::ostream &out, const Bureaucrat &b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".\n";
	return (out);
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("This Grade is too high\n");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("This Grade is too low\n");
}

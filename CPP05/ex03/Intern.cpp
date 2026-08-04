/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 16:23:31 by marvin            #+#    #+#             */
/*   Updated: 2026/05/18 16:23:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &cpy)
{
    *this = cpy;
}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern &cpy)
{
    if (this == &cpy)
		return (*this);
	return (*this);
}

AForm   *Intern::makeForm(std::string form, std::string target)
{
    int         x;
    std::string forms[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

    x = 0;
    while (forms[x] != form && x < 3)
        x++;
    switch (x)
    {
        case 0:
            std::cout << "Intern creates " << form << "\n";
            return (new ShrubberyCreationForm(target));
        case 1:
            std::cout << "Intern creates " << form << "\n";
            return (new RobotomyRequestForm(target));
        case 2:
            std::cout << "Intern creates " << form << "\n";
            return (new PresidentialPardonForm(target));
        default:
            std::cout << "The Intern couldn't find the form, therefore it was not created\n";
            return (NULL);
    }
}
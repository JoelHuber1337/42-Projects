/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 19:45:03 by marvin            #+#    #+#             */
/*   Updated: 2026/05/10 19:45:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("default")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cpy) : AForm(cpy.getName(), cpy.getSignGrade(), cpy.getExecGrade()), target(cpy.target)
{
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void    PresidentialPardonForm::execDoc() const
{
    std::cout << target << " has been pardoned by Zaphod Beeblebrox\n";
}

std::string PresidentialPardonForm::getTarget() const
{
    return (target);
}

PresidentialPardonForm& PresidentialPardonForm::operator = (const PresidentialPardonForm &cpy)
{
    if (this == &cpy)
        return (*this);
    target = cpy.target;
    return (*this);
}
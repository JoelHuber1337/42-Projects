/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 19:45:20 by marvin            #+#    #+#             */
/*   Updated: 2026/05/10 19:45:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy) : AForm(cpy.getName(), cpy.getSignGrade(), cpy.getExecGrade()), target(cpy.target)
{
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void    RobotomyRequestForm::execDoc() const
{
    int x = rand() % 2;

    std::cout << "*drilling noises*\n";
    if (x == 0)
        std::cout << "The Robotomy on " << target << " was unsuccessfull\n";
    else
        std::cout << target << " has been robotomized\n";
}

std::string RobotomyRequestForm::getTarget() const
{
    return (target);
}

RobotomyRequestForm& RobotomyRequestForm::operator = (const RobotomyRequestForm &cpy)
{
    if (this == &cpy)
        return (*this);
    target = cpy.target;
    return (*this);
}
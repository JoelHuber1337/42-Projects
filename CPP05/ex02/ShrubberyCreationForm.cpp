/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 19:45:25 by marvin            #+#    #+#             */
/*   Updated: 2026/05/10 19:45:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy) : AForm(cpy.getName(), cpy.getSignGrade(), cpy.getExecGrade()), target(cpy.target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator = (const ShrubberyCreationForm &cpy)
{
    if (this == &cpy)
        return (*this);
    target = cpy.target;
    return (*this);
}

void    ShrubberyCreationForm::execDoc() const
{
    std::string outFile = target + "_shrubbery";
    std::ofstream   output(outFile.c_str());

    if (!output.is_open())
        throw(ShrubberyCreationForm::OpenError());
    output << "                      ___\n";
    output << "                _,-'\"\"   \"\"\"\"`--.\n";
    output << "             ,-'          __,,-- \\\n";
    output << "           ,'    __,--\"\"\"\"dF      )\n";
    output << "          /   .-\"Hb_,--\"\"dF      /\n";
    output << "        ,'       _Hb ___dF\"-._,-'\n";
    output << "      ,'      _,-""""   ""--..__\n";
    output << "     (     ,-'                  `.\n";
    output << "      `._,'     _   _             ;\n";
    output << "       ,'     ,' `-'Hb-.___..._,-'\n";
    output << "       \\    ,'\"Hb.-'HH`-.dHF\"\n";
    output << "        `--'   \"Hb  HH  dF\"\n";
    output << "                \"Hb HH dF\n";
    output << "                 \"HbHHdF\n";
    output << "                  |HHHF\n";
    output << "                  |HHH|\n";
    output << "                  |HHH|\n";
    output << "                  |HHH|\n";
    output << "                  |HHH|\n";
    output << "                  dHHHb\n";
    output << "                .dFd|bHb.               o\n";
    output << "      o       .dHFdH|HbTHb.          o /\n";
    output << "\\ Y  |  \\__,dHHFdHH|HHhoHHb.__Krogg  Y\n";
    output << "##########################################";
    output.close();
}

std::string ShrubberyCreationForm::getTarget() const
{
    return (target);
}

const char	*ShrubberyCreationForm::OpenError::what() const throw()
{
	return ("Output file was not created or permissions are missing");
}
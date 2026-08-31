/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 13:21:03 by marvin            #+#    #+#             */
/*   Updated: 2026/08/31 19:18:24 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int  skipSpaces(std::string line, int x)
{
    while (isspace(line[x]) && line[x] && line[x] != '\n')
        x++;
    return (x);
}

int checkInputs(std::string str)
{
    if (str == "" || (size_t)skipSpaces(str, 0) == str.size())
        return (1);
    for (int x = 0; str[x]; x++)
    {
        if (!isspace(str[x]) && !isdigit(str[x]) && str[x] != '*' && str[x] != '-' && str[x] != '+' && str[x] != '/')
            return (1); 
        if (!isspace(str[x]) && !isspace(str[x + 1]) && str[x + 1] != '\0')
            return (1);
    }
    return (0);
}

int  revSkipSpaces(std::string line, int x)
{
    while (isspace(line[x]) && x >= 0)
        x--;
    return (x);
}

int main (int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error.\n";
        return (1);
    }
    if (checkInputs(av[1]))
        return (std::cerr << "Error.\n", 1);
    std::stack<std::string, std::list <std::string> >    number;
    std:: string                                        str = av[1];
    int                                                 x = str.size() - 1;
    
    x = revSkipSpaces(str, x);
    while (x >= 0)
    {
        number.push(str.substr(x, 1));
        x--;
        x = revSkipSpaces(str, x);
    }
    try
    {
        RPN    calc(number);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what();
        return (1);
    }
    
    return (0);
}
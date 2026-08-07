/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 20:05:36 by marvin            #+#    #+#             */
/*   Updated: 2026/05/27 20:05:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &cpy)
{
    *this = cpy;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter& ScalarConverter::operator = (ScalarConverter const &cpy)
{
	if (this == &cpy)
		return (*this);
	return (*this);
}

static int  calcPrecis(const std::string &string)
{
    size_t  pos = string.length() - 1;
    size_t  dot;

    if (string.find('.') == std::string::npos)
        return (1);
    dot = string.find('.');
    if (dot == pos)
        return (1);
    
    if (string[pos] == 'f' && dot == pos - 1)
        return (1);
    if (string.find('f') == std::string::npos)
        return (pos - dot);
    else
        return (pos - dot - 1);
}

static int  calcLen(const std::string &string)
{
    size_t  x = 0;

    if (string[x] == '+' || string[x] == '-')
        x++;
    while (string[x] == '0')
        x++;
    if (string.find('.') == std::string::npos)
        return (string.length() - x);
    return (string.find('.') - x);
}

static int  calcFLen(const std::string &string)
{
    size_t  x = 0;
    size_t  y = string.length() - 1;

    if (string[x] == '+' || string[x] == '-')
        x++;
    while (string[x] == '0')
        x++;
    if (string.find('.') == std::string::npos)
        return (string.length() - x);
    if (string.find('f') != std::string::npos)
    {
        y--;
        while (string[y] == '0')
        {
            y--;
            x++;
        }
        return (string.length() - x);
    }
    while (string[y] == '0')
    {
        y--;
        x++;
    }
    return (string.length() - x);
}

static int  checkFloat(size_t pos, const std::string &string, size_t &sign)
{
    if (pos == string.length() || pos == 0)
        return (0);
    if (pos == std::string::npos)
        return (0);
    if (string.find('f') == std::string::npos)
        return (0);
    for (size_t x = sign; x < pos; x++)
    {
        if (!isdigit(string[x]) )
            return (-1);
    }
    for (size_t x = pos + 1; x < string.length(); x++)
    {
        if (!isdigit(string[x]) && string[x] != 'f')
            return (-1);
        if (string[x] == 'f' && x != string.length() - 1)
            return (-1);
    }
    return (1);
}

static int  checkDouble(size_t pos, const std::string &string, size_t &sign)
{
    if (pos == string.length() || pos == 0)
        return (0);
    if (pos == std::string::npos)
        return (0);
    for (size_t x = sign; x < pos; x++)
    {
        if (!isdigit(string[x]))
            return (-1);
    }
    for (size_t x = pos + 1; x < string.length(); x++)
    {
        if (!isdigit(string[x]))
            return (-1);
    }
    return (2);
}

static int  checkInt(const std::string &string, size_t &sign)
{
    if (string.length() < 1)
        return (0);
    if (string == "-" || string == "+")
        return (0);
    for (size_t x = sign; x < string.length(); x++)
    {
        if (!isdigit(string[x]))
            return (0);
    }
    return (3);
}

static int  checkChar(const std::string &string)
{
    if (string.length() != 1)
        return (0);
    return (4);
}

static int  checkSpecial(const std::string &string)
{

    if (string == "nan" || string == "nanf" || string == "inf" || string == "inff" || string == "-inff" || string == "+inff" || string == "-inf" || string == "+inf")
        return (5);
    return (-1);
}

static int  checkType(const std::string &string)
{
    int check = 0;
    size_t x = 0;

    if (string[0] == '-' || string[0] == '+')
        x = 1;
    check = checkFloat(string.find('.'), string, x);
    if (check != 0)
        return (check);
    check = checkDouble(string.find('.'), string, x);
    if (check != 0)
        return (check);
    check = checkInt(string, x);
    if (check != 0)
        return (check);
    check = checkChar(string);
    if (check != 0)
        return (check);
    check = checkSpecial(string);
    return (check);
}

static void printFloat(const std::string &string)
{
    long double d;
    long        i;

    i = std::atol(string.c_str());
    d = std::strtold(string.c_str(), NULL);
    if (calcLen(string) > 13)
        i = (long)MAX_INT + 3;
    if (i > MAX_INT || i < MIN_INT)
    {
        std::cout << "char: Overflow\n";
        std::cout << "int: Overflow\n";
    }
    else
    {
        if (i > 127 || i < 0)
            std::cout << "char: Overflow\n";
        else if (isprint(static_cast<char>(i)))
            std::cout << "char: '" << static_cast<char>(d) << "'\n";
        else
            std::cout << "char: Non displayable\n";
        std::cout << "int: " << static_cast<int>(d) << "\n";
    }
    if (calcFLen(string) > 311 || d > MAX_DOUBLE || d < -MAX_DOUBLE)
    {
        std::cout << "float: Overflow\n";
        std::cout << "double: Overflow\n";
        return ;
    }
    if (calcFLen(string) > 42 || d > MAX_FLOAT || d < -MAX_FLOAT)
        std::cout << "float: Overflow\n";
    else
    {
        std::cout.setf(std::ios_base::fixed);
        std::cout << "float: " << std::setprecision(calcPrecis(string)) << static_cast<float>(d) << "f\n";
    }
    std::cout.setf(std::ios_base::fixed);
    std::cout << "double: " << std::setprecision(calcPrecis(string)) << static_cast<double>(d) << "\n";
}

static void printDouble(const std::string &string)
{
    long double d;
    long        i;

    i = std::atol(string.c_str());
    d = std::strtold(string.c_str(), NULL);
    if (calcLen(string) > 13)
        i = (long)MAX_INT + 3;
    if (i > MAX_INT || i < MIN_INT)
    {
        std::cout << "char: Overflow\n";
        std::cout << "int: Overflow\n";
    }
    else
    {
        if (i > 127 || i < 0)
            std::cout << "char: Overflow\n";
        else if (isprint(static_cast<char>(i)))
            std::cout << "char: '" << static_cast<char>(d) << "'\n";
        else
            std::cout << "char: Non displayable\n";
        std::cout << "int: " << static_cast<int>(d) << "\n";
    }
    if (calcFLen(string) > 311 || d > MAX_DOUBLE || d < -MAX_DOUBLE)
    {
        std::cout << "float: Overflow\n";
        std::cout << "double: Overflow\n";
        return ;
    }
    if (calcFLen(string) > 42 || d > MAX_FLOAT || d < -MAX_FLOAT)
        std::cout << "float: Overflow\n";
    else
    {
        std::cout.setf(std::ios_base::fixed);
        std::cout << "float: " << std::setprecision(calcPrecis(string)) << static_cast<float>(d) << "f\n";
    }
    std::cout.setf(std::ios_base::fixed);
    std::cout << "double: " << std::setprecision(calcPrecis(string)) << static_cast<double>(d) << "\n";
}

static void printInt(const std::string &string)
{
    long double d;
    long        i;

    i = std::atol(string.c_str());
    if (calcLen(string) > 13)
        i = (long)MAX_INT + 3;
    if (i > MAX_INT || i < MIN_INT)
    {
        std::cout << "char: Overflow\n";
        std::cout << "int: Overflow\n";
    }
    else
    {
        if (i > 127 || i < 0)
            std::cout << "char: Overflow\n";
        else if (isprint(static_cast<char>(i)))
            std::cout << "char: '" << static_cast<char>(i) << "'\n";
        else
            std::cout << "char: Non displayable\n";
        std::cout << "int: " << i << "\n";
    }
    d = std::strtold(string.c_str(), NULL);
    if (calcFLen(string) > 311 || d > MAX_DOUBLE || d < -MAX_DOUBLE)
    {
        std::cout << "float: Overflow\n";
        std::cout << "double: Overflow\n";
        return ;
    }
    if (calcFLen(string) > 42 || d > MAX_FLOAT || d < -MAX_FLOAT)
        std::cout << "float: Overflow\n";
    else
    {
        std::cout.setf(std::ios_base::fixed);
        std::cout << "float: " << std::setprecision(calcPrecis(string)) << static_cast<float>(i) << "f\n";
    }
    std::cout.setf(std::ios_base::fixed);
    std::cout << "double: " << std::setprecision(calcPrecis(string)) << static_cast<double>(i) << "\n";
}

static void printChar(const std::string &string)
{
    char    c = string[0];

    if (isprint(c))
      std::cout << "char: '" << c << "'\n";
    std::cout << "int: " << static_cast<int>(c) << "\n";
    std::cout << "float: " << static_cast<float>(c) << ".0f\n";
    std::cout << "double: " << static_cast<double>(c) << ".0\n";
}

static void printSpecial(const std::string &string)
{
    if (string == "nan" || string == "nanf")
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: nanf\n";
        std::cout << "double: nan\n"; 
    }
    if (string == "+inf" || string == "+inff" || string == "inf" || string == "inff")
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: inff\n";
        std::cout << "double: inf\n";
    }
    if (string == "-inf" || string == "-inff")
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: -inff\n";
        std::cout << "double: -inf\n";
    }
}

void    ScalarConverter::convert(const std::string &string)
{
    int check = checkType(string);
    
    switch (check)
    {
        case -1:
            std::cout << "Invalid Input\n"; 
            break ;
        case 1:
            printFloat(string);
            break ;
        case 2:
            printDouble(string);
            break ;
        case 3:
            printInt(string);
            break ;
        case 4:
            printChar(string);
            break ;
        case 5:
            printSpecial(string);
            break ;
    }
}

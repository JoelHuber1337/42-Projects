/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 20:26:40 by marvin            #+#    #+#             */
/*   Updated: 2026/08/27 20:48:24 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static int makeMap(std::fstream &input, std::map<std::string, std::string> &map)
{
    std::string line;
    size_t      pos;
    getline(input, line);
    if (input.eof())
		return (input.close(), 1);
    while (getline(input, line))
    {
        pos = line.find(',');
        if (pos == std::string::npos)
            map[line.substr(0, line.size() - 1)] = "";
        else
            map[line.substr(0, pos)] = line.substr(pos + 1, line.size() - 1);
    }
    return (0);
}

static int  skipSpaces(std::string line, int x)
{
    while (isspace(line[x]) && line[x] && line[x] != '\n')
        x++;
    return (x);
}

static int  revSkipSpaces(std::string line, int x)
{
    while (isspace(line[x]) && x >= 0)
        x--;
    return (x);
}

static int validCheck(std::string line)
{
    int     x = 0;
    int     dot = 0;

    while (x < 10)
    {
        if (!isdigit(line[x]) && x != 4 && x != 7)
            return (std::cout << "Error: bad input => " << line << "\n", 1);
        else if (line[x] != '-' && x == 4 && x == 7)
            return (std::cout << "Error: bad input => " << line << "\n", 1);
        x++;
    }
    x = skipSpaces(line, x);
    if (line[x] != '|')
        return (std::cout << "Error: bad input => " << line << "\n", 1);
    x++;
    x = skipSpaces(line, x);
    if (line[x] == '+')
        x++;
    if (line[x] == '-')
        return (std::cout << "Error: not a positive number.\n", 1);
    if (!isdigit(line[x]))
        return (std::cout << "Error: bad input => " << line << "\n", 1);
    while (line[x] == '.' || isdigit(line[x]) || isspace(line[x]))
    {
        if (line[x] == '.')
            dot++;
        if (dot > 1)
            return (std::cout << "Error: invalid value => " << line.substr(line.find('|') + 1) << "\n", 1);
        if (dot == 1 && line.find('.') + 3 < (size_t)x)
            return (std::cout << "Error: only accepting three decimal values" << line.substr(line.find('|') + 1) << "\n", 1);
        x++;
    }
    if (line[x] != '\n' && line[x] != '\0')
        return (std::cout << "Error invalid value => " << line.substr(line.find('|') + 1) << "HAIII\n", 1);
    return (0);
}

static void findData(std::string line, std::map<std::string, std::string> data)
{
    double       value = atof(line.substr(line.find('|') + 1).c_str());
    std::string date = line.substr(0, revSkipSpaces(line, line.find('|') - 1) + 1);

    if (value >= (double)1000)
        std::cout << "Error: too large a number.\n";
    else if (value <= (double)0)
        std::cout << "Error: number cannot be zero.\n";
    else if (data.find(date) != data.end())
        std::cout << date << " => " << value << " = " << value * atof((data[date]).c_str()) << "\n";
    else
    {
        std::map<std::string, std::string>::iterator it = data.lower_bound(date);
        if (it != data.begin()) 
        {
            --it;
            std::cout << date << " => " << value << " = " << value * atof((data[it->first]).c_str()) << "\n";
        }
        else
            std::cout << "Error: no previous date exists.\n";
    }
}

int bitcoinExchange(std::fstream &finput, std::fstream &fdata)
{
    std::map<std::string, std::string>      data;
    std::string                             line;
    size_t                                     pos;

    if (makeMap(fdata, data))
        return (finput.close(), std::cout << "Error: Data File is empty\n", 1);
    getline(finput, line);
    if (finput.eof())
        return (finput.close(), fdata.close(), 0);
    while (getline(finput, line))
    {
        pos = line.find('|');
        if (pos == std::string::npos)
            std::cout << "Error: bad input => " << line << "\n";
        else if (validCheck(line))
            ;
        else
            findData(line, data);
    }
    return (0);
}
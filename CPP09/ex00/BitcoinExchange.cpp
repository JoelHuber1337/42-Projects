/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 20:26:40 by marvin            #+#    #+#             */
/*   Updated: 2026/08/14 20:26:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int makeMapInput(std::fstream &input, std::map<std::string, std::string> &map)
{
    std::string line;
    size_t      pos;
    getline(input, line);
    if (input.eof())
		return (input.close(), 1);
    while (getline(input, line))
    {
        pos = line.find('|');
        if (pos == std::string::npos)
            map[line.substr(0, line.size() - 1)] = "hey";
        else
        {
            std::cout << "pos = " << pos << "line size = " << line.size() << "\n";
            map[line.substr(0, pos - 1)] = line.substr(pos + 2, line.size() - 1);
        }
    }
    return (0);
}

int makeMapData(std::fstream &input, std::map<std::string, std::string> &map)
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

int bitcoinExchange(std::fstream &finput, std::fstream &fdata)
{
    std::map<std::string, std::string>    input;
    std::map<std::string, std::string>    data;

    if (makeMapInput(finput, input))
        return (fdata.close(), std::cout << "Error: File is empty\n", 1);
    if (makeMapData(fdata, data))
        return (finput.close(), std::cout << "Error: Data File is empty\n", 1);
    for (std::map<std::string, std::string>::const_iterator it = input.begin(); it != input.end(); ++it)
        std::cout << it->first << " = " << it->second << ";";
    std::cout << "\n\n SECOND FILE:\n\n";
    for (std::map<std::string, std::string>::const_iterator it = data.begin(); it != data.end(); ++it)
        std::cout << it->first << " = " << it->second << ";";
    return (0);
}
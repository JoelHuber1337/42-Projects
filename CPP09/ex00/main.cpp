/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 15:26:45 by marvin            #+#    #+#             */
/*   Updated: 2026/08/11 15:26:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	fileChecks(std::string	file)
{
	std::string	line;

	std::fstream	input(file.c_str());
	if (!input.is_open())
	{
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}
    std::getline(input, line);
    if (line.compare(0, 12, "date | value") == 0)
    {
        for (size_t x = 12; x < line.size(); x++)
            if (!isspace(line[x]))
                return (input.close(), std::cout << "Error: File Formatting is incorrect" << std::endl, 1);
    }
    else if (line.compare(0, 18, "date,exchange_rate") == 0)
    {
        for (size_t x = 18; x < line.size(); x++)
            if (!isspace(line[x]))
                return (input.close(), std::cout << "Error: File Formatting is incorrect" << std::endl, 1);
    }
    else
    {
        return (input.close(), std::cout << "Error: File Formatting is incorrect" << std::endl, 1);
    }
	while (std::getline(input, line))
		;
	if (input.eof())
		return (input.close(), 0);
	std::cout << "Error: getline failed." << std::endl;
	return (input.close(), 1);
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error: could not open file.\n";
        return (1);
    }
    std::string     sdata = "data.csv";
    if (fileChecks(sdata) == 1)
        return (1);
    if (fileChecks(av[1]) == 1)
        return (1);
    std::fstream	input(av[1]);
    std::fstream    data(sdata.c_str());
    return (bitcoinExchange(input, data));
}
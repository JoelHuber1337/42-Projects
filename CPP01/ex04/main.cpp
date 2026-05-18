/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 18:38:58 by johuber           #+#    #+#             */
/*   Updated: 2025/12/09 15:13:57 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

int	fileChecks(std::string	file)
{
	std::string	line;

	std::fstream	input(file.c_str());
	if (!input.is_open())
	{
		std::cout << "No permissions to access the file or file does not exist." << std::endl;
		return (1);
	}
	while (std::getline(input, line))
		;
	if (input.eof())
		return (input.close(), 0);
	std::cout << "Getline failed\n" << std::endl;
	return (input.close(), 1);
}

std::string	replaceLine(std::string line, std::string str1, std::string str2)
{
	size_t	start = 0;
	size_t	last = 0;
	while ((start = line.find(str1, start)) != std::string::npos)
	{
		line = line.substr(0, start) + str2 + line.substr(start + str1.length());
		start = start + str1.length();
		last = start;
	}
	return (line);
}

int	main(int arc, char **arv)
{
	if (arc != 4 || !arv || !arv[1] || !arv[2] || !arv[3] || !arv[2][0])
	{
		std::cout << "Needs 3 Inputs, a file name, a string to search for and a string to replace it with, string to replace can be empty\n";
		return (1);
	}
	std::string	inFile = arv[1];
	std::string	str1 = arv[2];
	std::string	str2 = arv[3];
	if (fileChecks(inFile))
		return (1);
	std::string line;
	std::string	outFile = inFile + ".replace";
	std::fstream	input(inFile.c_str());
	std::ofstream	output(outFile.c_str());
	if (!output.is_open())
	{
		std::cout << "Output file was not created or permissions are missing\n";
		input.close();
		return (1);
	}
	while (std::getline(input, line))
	{
		if (line.find(str1, 0) != std::string::npos)
			line = replaceLine(line, str1, str2);
		output << line;
		output << "\n";
	}
	if (input.eof())
		return (input.close(), output.close(), 0);
	std::cout << "Getline failed\n" << std::endl;
	input.close();
	output.close();
	return (1);
}

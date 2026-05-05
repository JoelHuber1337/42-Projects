/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:21:42 by johuber           #+#    #+#             */
/*   Updated: 2025/12/05 20:29:18 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	ph_add(std::string line, PhoneBook &PhoneBook, int x)
{
	int	y = 0;

	while (x >= 8)
		x = x % 8;
	Contact &Con = PhoneBook.getContact(x);
	Con.setFname(line);
	while (!std::cin.fail() && y != 5)
	{
		if (y == 0)
			std::cout << "Enter the first name of your new Contact:\n";
		if (y == 1)
			std::cout << "Enter the last name of your new Contact:\n";
		if (y == 2)
			std::cout << "Enter the Nickname of your new Contact\n";
		if (y == 3)
			std::cout << "Enter the Phone Number of your new Contact\n";
		if (y == 4)
			std:: cout << "Enter the Darkest Secret of your new Contact\n";
		std::getline(std::cin, line);
		if ((line.empty() || !line[0]))
		{
			std::cout << "\033[31m";
			if (y == 0)
				std::cout << "First name cannot be empty\n";
			if (y == 1)
				std::cout << "Last name cannot be empty\n";
			if (y == 2)
				std::cout << "Nickname cannot be empty\n";
			if (y == 3)
				std::cout << "Phone Number cannot be empty\n";
			if (y == 4)
				std::cout << "Darkest Secret cannot be empty\n";
			std::cout << "\033[0m";
		}
		else
		{
			if (y == 0)
				Con.setFname(line);
			if (y == 1)
				Con.setLname(line);
			if (y == 2)
				Con.setNname(line);
			if (y == 3)
				Con.setPnumber(line);
			if (y == 4)
				Con.setSecret(line);
			y++;
		}
	}
	std::cout << "\033[0;38;2;187;161;79;49mContact created, well done!\n\033[0m";
}

void	ph_search(PhoneBook PhoneBook, int x)
{
	std::string	line;
	int			res;

	if (x == 0)
	{
		std::cout << "\033[31mAdd a Contact before you search\n\033[0m";
		return ;
	}
	std::cout << "Searching your Contact list...\n";
	for (int i = 0; i < 8; i++)
	{
		if (PhoneBook.getContact(i).getFname().empty())
			break ;
		std::cout << std::setiosflags(std::ios::right) << "|" << std::setw(10) << i;
		if (PhoneBook.getContact(i).getFname().length() > 10)
			std::cout << std::setiosflags(std::ios::right) << "|" << std::setw(10) << PhoneBook.getContact(i).getFname().substr(0, 9).append(".") << "|";
		else
			std::cout << std::setiosflags(std::ios::right) << "|" << std::setw(10) << PhoneBook.getContact(i).getFname() << "|";
		if (PhoneBook.getContact(i).getLname().length() > 10)
			std::cout << std::setiosflags(std::ios::right) << std::setw(10) << PhoneBook.getContact(i).getLname().substr(0, 9).append(".") << "|";
		else
			std::cout << std::setiosflags(std::ios::right) << std::setw(10) << PhoneBook.getContact(i).getLname() << "|";
		if (PhoneBook.getContact(i).getNname().length() > 10)
			std::cout << std::setiosflags(std::ios::right) << std::setw(10) << PhoneBook.getContact(i).getNname().substr(0, 9).append(".") << "|" << "\n";
		else
			std::cout << std::setiosflags(std::ios::right) << std::setw(10) << PhoneBook.getContact(i).getNname() << "|" << "\n";
	}
	std::cout << "\nEnter the Index of the Contact you would like to see:\n";
	std::getline(std::cin, line);
	while (line.length() != 1 || !isdigit(line[0]))
	{
		std::cout << "\033[31mIndex can only be a single Digit\n\033[0m";
		std::getline(std::cin, line);
	}
	res = line[0] - '0';
	while (PhoneBook.getContact(res).getFname().empty())
	{
		std::cout << "\033[31mContact does not exist, pick one from the list provided.\n\033[0m";
		std::getline(std::cin, line);
		while (line.length() != 1 || !isdigit(line[0]))
		{
			std::cout << "\033[31mIndex can only be a single Digit\n\033[0m";
			std::getline(std::cin, line);
		}
		res = line[0] - '0';
	}
	std::cout << "\033[0;38;2;187;161;79;49mSuccess! Providing Contact Information:\n\033[0m";
	std::cout << "Index : " << res << "\n";
	std::cout << "First Name :" << PhoneBook.getContact(res).getFname() << "\n";
	std::cout << "Last Name :" << PhoneBook.getContact(res).getLname() << "\n";
	std::cout << "Nick Name :" << PhoneBook.getContact(res).getNname() << "\n";
	std::cout << "Phone Number :" << PhoneBook.getContact(res).getPnumber() << "\n";
	std::cout << "Darkest Secret :" << PhoneBook.getContact(res).getSecret() << "\n";
	std::cout << "\033[0;38;2;187;161;79;49mNow you know everything, returning to Main Menu\n\033[0m";
}

int	main()
{
	PhoneBook	PhoneBook;
	std::string		line;
	int				x;

	x = 0;
	print_instructions();
	while(!std::cin.fail())
	{
		std::getline(std::cin, line);
		if (line == "ADD")
		{
			ph_add(line, PhoneBook, x);
			x++;
		}
		if (line == "SEARCH")
			ph_search(PhoneBook, x);
		if (line == "EXIT")
		{
			std::cout << "\033[0;38;2;187;161;79;49mPhonebook closed, goodbye!\033[0m" << std::endl;
			return (0);
		}
	}
	return (1);
}

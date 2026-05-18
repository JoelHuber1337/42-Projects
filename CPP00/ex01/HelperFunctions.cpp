/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HelperFunctions.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:07:12 by johuber           #+#    #+#             */
/*   Updated: 2025/12/02 14:27:32 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	print_instructions()
{
	std::cout << "\033[32m";
	std::cout << "*******************************\n";
	std::cout << "*Welcome to your new Phonebook*\n";
	std::cout << "*Here is a list of Commands****\n";
	std::cout << "*ADD - Adds new Contacts*******\n";
	std::cout << "*SEARCH - Shows your contacts**\n";
	std::cout << "*EXIT - Closes your phonebook**\n";
	std::cout << "*******************************\n";
	std::cout << "\033[31m\n";
	std::cout << "*******************************\n";
	std::cout << "*!!WARNING!! Closing your******\n";
	std::cout << "*Phonebook will delete Contacts\n";
	std::cout << "*We arent liable for your loss*\n";
	std::cout << "*******************************\n";
	std::cout << "\033[0m";
}

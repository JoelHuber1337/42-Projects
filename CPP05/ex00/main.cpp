/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:17:55 by johuber           #+#    #+#             */
/*   Updated: 2026/04/22 17:58:09 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	correct("Correct", 1);
//	Bureaucrat	wrong("false", 0);
	Bureaucrat	defaultCopy;
	Bureaucrat	copy (correct);
	
	std::cout << "Checking Constructors, Correct = Asssignment Constructor, Default = Default Constructor, Correct = Copy Constructor\n";
	std::cout << "-------------------------------------\n";
	std::cout << correct << "\n";
	std::cout << defaultCopy << "\n";
	std::cout << copy << "\n";

	defaultCopy = correct;
	std::cout << "Checking the Copy Assignment Operator, copying correct into defaultCopy\n";
	std::cout << "------------------------------------\n";
	std::cout << defaultCopy << "\n";
	std::cout << "Overloading the Ostream operator tested throughout the other tests\n";

	std::cout << "\nTesting exceptions:\n";
	std::cout << "------------------------------------\n";
//	std::cout << wrong << "\n";
	std::string t = "test";
	try
	{
		std::cout << "Creating grade 0:\n";
		Bureaucrat	test(t, 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	try
	{
		std::cout << "Creating grade 151:\n";
		Bureaucrat	test(t, 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	try
	{
		std::cout << "Creating grade 1 and incrementing it by 1:\n";
		Bureaucrat	test(t, 1);
		test.incrementGrade(1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	try
	{
		std::cout << "Creating grade 150 and decrementing it by 1:\n";
		Bureaucrat	test(t, 150);
		test.decrementGrade(1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
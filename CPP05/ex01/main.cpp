/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:17:55 by johuber           #+#    #+#             */
/*   Updated: 2026/04/24 20:39:12 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	Bureaucrat	correct("Correct", 1);
//	Bureaucrat	wrong("false", 0);
	Bureaucrat	defaultCopy;
	Bureaucrat	copy(correct);
	Form		Fcorrect("Fcorrect", 1, 1);
//	Form		Fwrong("false", 0, 0);
	Form		FdefaultCopy;
	Form		Fcopy(Fcorrect);
	
	std::cout << "Checking Constructors, Correct = Asssignment Constructor, Default = Default Constructor, Correct = Copy Constructor\n";
	std::cout << "-------------------------------------\n";
	std::cout << correct << "\n";
	std::cout << defaultCopy << "\n";
	std::cout << copy << "\n";
	std::cout << Fcorrect << "\n";
	std::cout << FdefaultCopy << "\n";
	std::cout << Fcopy << "\n";

	defaultCopy = correct;
	FdefaultCopy = Fcorrect;
	std::cout << "Checking the Copy Assignment Operator, copying correct into defaultCopy\n";
	std::cout << "------------------------------------\n";
	std::cout << defaultCopy << "\n";
	std::cout << FdefaultCopy << "\n";
	std::cout << "Overloading the Ostream operator tested throughout the other tests\n";

	std::cout << "\nTesting exceptions:\n";
	std::cout << "------------------------------------\n";
//	std::cout << wrong << "\n";
//	std::cout << Fwrong << "\n";
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
		std::cout << e.what() << "\n";
	}
	std::cout << "Creating forms with invalid grades, first 0 and then 151:\n";
	try
	{
		Form ftest(t, 0, 42);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	try
	{
		Form ftest(t, 42, 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	try
	{
		Form ftest(t, 0, 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	try
	{
		Form ftest(t, 151, 42);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	try
	{
		Form ftest(t, 42, 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	try
	{
		Form ftest(t, 151, 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	std::cout << "------------------------------------\n";
	std::cout << "Testing Form signability:\n";
	try
	{
		Fcorrect.beSigned(correct);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	std::cout << Fcorrect << "\n";
	try
	{
		Fcorrect.beSigned(copy);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	std::cout << Fcorrect << "\n";
	Form		Fcorrect2("Fcorrect2", 1, 1);
	Bureaucrat	weak("Weak", 150);
	try
	{
		Fcorrect2.beSigned(weak);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	std::cout << Fcorrect2 << "\n";
	Form		Fcorrect3("Fcorrect3", 1, 1);
	try
	{
		Fcorrect3.beSigned(weak);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	Bureaucrat second("Second", 2);
	try
	{
		Fcorrect3.beSigned(second);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	return (0);
}
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
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

void	ConstructorCheck()
{
	Bureaucrat				correct("Correct", 1);
	Bureaucrat				defaultCopy;
	Bureaucrat				copy(correct);
	ShrubberyCreationForm	sdef;
	ShrubberyCreationForm	sarg("Broom");
	ShrubberyCreationForm	scopy(sarg);
	PresidentialPardonForm	pdef;
	PresidentialPardonForm	parg("Sorry");
	PresidentialPardonForm	pcopy(parg);
	RobotomyRequestForm		rdef;
	RobotomyRequestForm		rarg("robot");
	RobotomyRequestForm		rcopy(rarg);
	ShrubberyCreationForm 	test2("hey");
	RobotomyRequestForm		test3("hey");
	PresidentialPardonForm	test4("hey");

	std::cout << "Checking Constructors, Correct = Asssignment Constructor, Default = Default Constructor, Correct = Copy Constructor\n";
	std::cout << "-------------------------------------\n";
	std::cout << correct << "\n";
	std::cout << defaultCopy << "\n";
	std::cout << copy << "\n";
	std::cout << sdef << "\n";
	std::cout << sarg << "\n";
	std::cout << scopy << "\n";
	std::cout << pdef << "\n";
	std::cout << parg << "\n";
	std::cout << pcopy << "\n";
	std::cout << rdef << "\n";
	std::cout << rarg << "\n";
	std::cout << rcopy << "\n";
	defaultCopy = correct;
	scopy = sdef;
	pcopy = pdef;
	rcopy = rdef;
	std::cout << "Checking the Copy Assignment Operator, copying correct into defaultCopy, for Forms were are checking the Target changes\n";
	std::cout << "------------------------------------\n";
	std::cout << defaultCopy << "\n";
	std::cout << scopy.getTarget() << "\n";
	std::cout << pcopy.getTarget() << "\n";
	std::cout << rcopy.getTarget() << "\n";
	scopy = test2;
	rcopy = test3;
	pcopy = test4;
	std::cout << scopy.getTarget() << "\n";
	std::cout << pcopy.getTarget() << "\n";
	std::cout << rcopy.getTarget() << "\n";
	std::cout << "Overloading the Ostream operator tested throughout the other tests\n";
}

void	ExceptionCheck()
{
//	Bureaucrat	wrong("false", 0);
	std::cout << "\nTesting exceptions (Bureaucrats only):\n";
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
		std::cout << e.what() << "\n";
	}
	std::cout << "------------------------------------\n";

}

void	SignabilityCheck()
{
	Bureaucrat				correct("Correct", 1);
	Bureaucrat				wrong("Wrong", 150);
	ShrubberyCreationForm	sdef;
	PresidentialPardonForm	pdef;
	RobotomyRequestForm		rdef;
	Bureaucrat				sexact("SExact", 145);
	Bureaucrat				pexact("PExact", 25);
	Bureaucrat				rexact("RExact", 72);
	ShrubberyCreationForm	sdef2;
	PresidentialPardonForm	pdef2;
	RobotomyRequestForm		rdef2;

	std::cout << "Testing Form signability:\n";
	try
	{
		std::cout << wrong << " trying to sign " << sdef << "\n";
		sdef.beSigned(wrong);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	std::cout << "------" << sdef << "\n";
	try
	{
		std::cout << correct << " trying to sign " << sdef << "\n";
		sdef.beSigned(correct);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	std::cout << "------" << sdef << "\n";
	try
	{
		std::cout << wrong << " trying to sign " << pdef << "\n";
		pdef.beSigned(wrong);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	std::cout << "------" << pdef << "\n";
	try
	{
		std::cout << correct << " trying to sign " << pdef << "\n";
		pdef.beSigned(correct);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	std::cout << "------" << pdef << "\n";
	try
	{
		std::cout << wrong << " trying to sign " << rdef << "\n";
		rdef.beSigned(wrong);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	std::cout << "------" << rdef << "\n";
	try
	{
		std::cout << correct << " trying to sign " << rdef << "\n";
		rdef.beSigned(correct);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	std::cout << "------" << sdef << "\n";
	try
	{
		std::cout << sexact << " trying to sign " << sdef2 << "\n";
		rdef2.beSigned(sexact);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	std::cout << "------" << sdef2 << "\n";
	try
	{
		std::cout << pexact << " trying to sign " << pdef2 << "\n";
		pdef2.beSigned(pexact);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	std::cout << "------" << pdef2 << "\n";
	try
	{
		std::cout << rexact << " trying to sign " << rdef2 << "\n";
		rdef2.beSigned(rexact);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	std::cout << "------" << rdef2 << "\n";
	try
	{
		std::cout << sexact << " trying to sign " << sdef2 << "\n";
		rdef2.beSigned(sexact);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	std::cout << "------" << sdef2 << "\n";
	try
	{
		std::cout << pexact << " trying to sign " << pdef2 << "\n";
		pdef2.beSigned(pexact);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	std::cout << "------" << pdef2 << "\n";
	try
	{
		std::cout << rexact << " trying to sign " << rdef2 << "\n";
		rdef2.beSigned(rexact);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	std::cout << "------" << rdef2 << "\n";
	std::cout << "------------------------------------\n";
}

void	ExecutionCheck()
{
	Bureaucrat				correct("Correct", 1);
	Bureaucrat				wrong("Wrong", 150);
	ShrubberyCreationForm	sdef;
	PresidentialPardonForm	pdef;
	RobotomyRequestForm		rdef;
	Bureaucrat				sexact("SExact", 137);
	Bureaucrat				pexact("PExact", 5);
	Bureaucrat				rexact("RExact", 45);
	PresidentialPardonForm	pdef2;
	RobotomyRequestForm		rdef2;
	ShrubberyCreationForm	sdef2;
	ShrubberyCreationForm	sdef3("Default2");
	PresidentialPardonForm	pdef3("Peter");
	RobotomyRequestForm		rdef3("Peter");

	std::cout << "Testing Form executability:\n";
	sdef.beSigned(correct);
	pdef.beSigned(correct);
	rdef.beSigned(correct);
	sdef3.beSigned(correct);
	pdef3.beSigned(correct);
	rdef3.beSigned(correct);
	std::cout << "\n";
	wrong.executeForm(sdef);
	correct.executeForm(sdef);
	sexact.executeForm(sdef3);
	wrong.executeForm(pdef);
	correct.executeForm(pdef);
	pexact.executeForm(pdef3);
	wrong.executeForm(rdef);
	correct.executeForm(rdef);
	rexact.executeForm(rdef3);
	std::cout << "\nTesting Unsigned Form executability:\n";
	correct.executeForm(sdef2);
	correct.executeForm(rdef2);
	correct.executeForm(pdef2);
	std::cout << "------------------------------------\n";
}

int	main()
{	
	ConstructorCheck();
	ExceptionCheck();
	SignabilityCheck();
	ExecutionCheck();
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 20:30:27 by johuber           #+#    #+#             */
/*   Updated: 2025/12/29 21:46:47 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
//	Animal wrong;
	Animal	*animals[20];
	Cat		test1;
	Cat		test2;
	Dog		test3;
	Dog		test4;

	std::cout << "Making animal arrays\n";
	for (int i = 0; i < 20; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		std::cout << std::endl;
	}
	std::cout << "Polymorphism works\n";	
	test1.getBrain()->setIdea("Meow", 0);
	test2.getBrain()->setIdea("GUP", 1);
	test3.getBrain()->setIdea("BARK", 0);
	test4.getBrain()->setIdea("WOOF", 1);

	std::cout << "Testing ideas: \n";
	std::cout << "Cat test 1 first Idea: " << test1.getBrain()->getIdea(0) << "\n";
	std::cout << "Cat test 2 second Idea: " << test2.getBrain()->getIdea(1) << "\n";
	std::cout << "Dog test 3 first Idea: " << test3.getBrain()->getIdea(0) << "\n";
	std::cout << "Dog test 4 first Idea: " << test4.getBrain()->getIdea(1) << "\n";

	std::cout << "\nIdeas working, testing deep copy behaviour\n";
	test1 = test2;
	std::cout << "Cat test 1 first Idea after copying test2 brain: " << test1.getBrain()->getIdea(0) << "\n";
	std::cout << "Cat test 1 second Idea after copying test2 brain: " << test1.getBrain()->getIdea(1) << "\n";
	std::cout << "Setting Cat test 1 a new first idea\n";
	test1.getBrain()->setIdea("Meeeeeoooooww", 0);
	std::cout << "Cat test 1 first new Idea: " << test1.getBrain()->getIdea(0) << "\n";
	std::cout << "Checking if test 2 remains unchanged: \n";
	std::cout << "Cat test 2 first Idea: " << test2.getBrain()->getIdea(0) << "\n";
	std::cout << "Cat test 2 second Idea: " << test2.getBrain()->getIdea(1) << "\n";
	std::cout << "\nDeep copy behaviour checked. Now Dogs: \n";
	test3 = test4;
	std::cout << "Dog test 3 first Idea after copying test4 brain: " << test3.getBrain()->getIdea(0) << "\n";
	std::cout << "Dog test 3 second Idea after copying test4 brain: " << test4.getBrain()->getIdea(1) << "\n";
	std::cout << "Setting Dog test 3 a new first idea\n";
	test3.getBrain()->setIdea("WROOOOFFFFF", 0);
	std::cout << "Dog test 3 first new Idea: " << test3.getBrain()->getIdea(0) << "\n";
	std::cout << "Checking if test 4 remains unchanged: \n";
	std::cout << "Dog test 4 first Idea: " << test4.getBrain()->getIdea(0) << "\n";
	std::cout << "Dog test 4 second Idea: " << test4.getBrain()->getIdea(1) << "\n";
	std::cout << "\n\nCalling destuctors" << std::endl;
	for (int i = 0; i < 20; i++)
		delete animals[i];
	return (0);
}

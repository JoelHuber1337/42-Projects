/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 20:30:27 by johuber           #+#    #+#             */
/*   Updated: 2025/12/30 14:24:16 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* test0 = new Animal();
	const Animal* test1 = new Dog();
	const Animal* test2 = new Cat();

	std::cout << test1->getType() << " " << std::endl;
	std::cout << test2->getType() << " " << std::endl;
	test1->makeSound();
	test2->makeSound();
	test0->makeSound();
	WrongAnimal	*test3 = new WrongAnimal;
	WrongAnimal	*test4 = new WrongCat;
	test3->makeSound();
	test4->makeSound();
	std::cout << std::endl;
	delete test0;
	delete test1;
	delete test2;
	delete test3;
	delete test4;
}

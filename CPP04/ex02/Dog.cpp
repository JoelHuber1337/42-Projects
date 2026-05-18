/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 20:30:33 by johuber           #+#    #+#             */
/*   Updated: 2025/12/29 21:45:36 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	this->brain = new Brain;
	std::cout << "Dog Default Constructor called\n";
}

Dog::Dog(const Dog &d) : Animal("Dog")
{
	this->brain = new Brain;
	for (int x = 0; x < 100; x++)
		this->brain->setIdea(d.brain->getIdea(x), x);
	std::cout << "Dog Copy Constructor called\n";
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog Deconstructor called\n";
}

Dog&	Dog::operator = (const Dog &copy)
{
	if (this == &copy)
		return (*this);
	this->type = copy.type;
	delete this->brain;
	this->brain = new Brain(*copy.brain);
	return (*this);
}

Brain*	Dog::getBrain(void) const
{
	return (this->brain);
}

void		Dog::makeSound(void) const
{
	std::cout << "Woof Woof Wooof Barkk!\n";	
}
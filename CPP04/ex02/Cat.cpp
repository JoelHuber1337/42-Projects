/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 20:30:38 by johuber           #+#    #+#             */
/*   Updated: 2025/12/29 21:45:40 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	this->brain = new Brain;
	std::cout << "Cat Default Constructor called\n";	
}

Cat::Cat(const Cat &d) : Animal("Cat")
{
	this->brain = new Brain;
	for (int x = 0; x < 100; x++)
		this->brain->setIdea(d.brain->getIdea(x), x);
	std::cout << "Cat Copy Constructor called\n";
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat Destructor called\n";
}

Cat&	Cat::operator = (const Cat &copy)
{
	if (this == &copy)
		return (*this);
	this->type = copy.type;
	delete this->brain;
	this->brain = new Brain(*copy.brain);
	return (*this);
}

Brain*	Cat::getBrain(void) const
{
	return (this->brain);
}

void		Cat::makeSound(void) const
{
	std::cout << "Meeeeowww\n";
}

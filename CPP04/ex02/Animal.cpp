/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 20:30:44 by johuber           #+#    #+#             */
/*   Updated: 2025/12/28 21:01:14 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Default Constructor of Animal called\n";
}

Animal::Animal(std::string type)
{
	this->type = type;
	std::cout << "Argument Constructor of Animal called\n";
}

Animal::Animal(Animal &clone)
{
	*this = clone;
	std::cout << "Copy Constructor of Animal called\n";
}

Animal::~Animal()
{
	std::cout << "Animal Deconstructor called\n";
}

void	Animal::setType(std::string type)
{
	this->type = type;
}

const std::string&	Animal::getType(void) const
{
	return(this->type);
}

Animal&			Animal::operator = (const Animal &copy)
{
	if (this == &copy)
		return (*this);
	this->type = copy.type;
	return (*this);
}

void	Animal::makeSound(void) const
{
	std::cout << "\"........\"" << std::endl;
}
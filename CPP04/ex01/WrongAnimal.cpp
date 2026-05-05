/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 20:30:24 by johuber           #+#    #+#             */
/*   Updated: 2025/12/23 18:57:09 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Default Constructor of WrongAnimal called\n";
}

WrongAnimal::WrongAnimal(std::string type)
{
	this->type = type;
	std::cout << "Argument Constructor of WrongAnimal called\n";
}

WrongAnimal::WrongAnimal(WrongAnimal &clone)
{
	*this = clone;
	std::cout << "Copy Constructor of WrongAnimal called\n";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Deconstructor of WrongAnimal called\n";
}

WrongAnimal&			WrongAnimal::operator = (const WrongAnimal &b)
{
	this->type = b.type;
	return (*this);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "\"........\"" << std::endl;
}
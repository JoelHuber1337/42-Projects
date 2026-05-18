/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 20:30:33 by johuber           #+#    #+#             */
/*   Updated: 2025/12/23 19:10:16 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog Default Constructor called\n";
}

Dog::Dog(const Dog &d)
{
	*this = d;
	std::cout << "Dog Copy Constructor called\n";
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called\n";	
}

void		Dog::makeSound(void) const
{
	std::cout << "Woof Woof Wooof Barkk!\n";	
}
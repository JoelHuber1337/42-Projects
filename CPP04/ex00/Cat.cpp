/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 20:30:38 by johuber           #+#    #+#             */
/*   Updated: 2025/12/23 19:09:53 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat Default Constructor called\n";	
}

Cat::Cat(const Cat &d)
{
	*this = d;
	std::cout << "Cat Copy Constructor called\n";
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called\n";
}

void		Cat::makeSound(void) const
{
	std::cout << "Meeeeowww\n";
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 20:30:12 by johuber           #+#    #+#             */
/*   Updated: 2025/12/23 19:08:11 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat Default Constructor called\n";	
}

WrongCat::WrongCat(const WrongCat &d)
{
	*this = d;
	std::cout << "WrongCat Copy Constructor called\n";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called\n";
}

void		WrongCat::makeSound(void) const
{
	std::cout << "Meeeeowww\n";
}
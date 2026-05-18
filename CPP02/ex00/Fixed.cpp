/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:34:40 by johuber           #+#    #+#             */
/*   Updated: 2025/12/14 21:19:29 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->fixedValue = 0;
	std::cout << "Default constructor called\n";
}
	
Fixed::Fixed(const Fixed &a)
{
	std::cout << "Copy constructor called\n";
	this->fixedValue = a.getRawBits();
}
	
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

void Fixed::setRawBits(int const raw)
{
	this->fixedValue = raw;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (this->fixedValue);
}

Fixed&	Fixed::operator = (const Fixed &b)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &b)
		this->fixedValue = b.getRawBits();
	return (*this);
}

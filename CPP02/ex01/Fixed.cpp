/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:34:40 by johuber           #+#    #+#             */
/*   Updated: 2025/12/14 21:39:15 by johuber          ###   ########.fr       */
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

Fixed::Fixed(const int x)
{
	std::cout << "Int constructor called\n";
	this->fixedValue = x << this->bits;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called\n";
	this->fixedValue = roundf(num * (1 << this->bits));
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

float	Fixed::toFloat(void) const
{
	return ((float)this->fixedValue / (float)(1 << this->bits));
}

int	Fixed::toInt(void) const
{
	return (this->fixedValue >> this->bits);
}

Fixed&	Fixed::operator = (const Fixed &b)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &b)
		this->fixedValue = b.getRawBits();
	return (*this);
}

std::ostream&	operator << (std::ostream &out, const Fixed &b)
{
	out << b.toFloat();
	return (out);
}

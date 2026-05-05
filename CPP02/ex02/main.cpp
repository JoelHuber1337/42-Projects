/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:34:36 by johuber           #+#    #+#             */
/*   Updated: 2025/12/17 20:15:21 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) 
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	 std::cout << a << std::endl;
	 std::cout << ++a << std::endl;
	 std::cout << a << std::endl;
	 std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	

	std::cout << "max " << Fixed::max(a, b) << std::endl;
	std::cout << "min " << Fixed::min(a, b) << std::endl;
	
	std::cout << "logic\n";
	std::cout << "> " << (a > b) << std::endl;
	std::cout << "< " << (a < b) << std::endl;
	std::cout << ">= " << (a >= b) << std::endl;
	std::cout << "<= " << (a <= b) << std::endl;
	std::cout << "== " << (a == b) << std::endl;
	std::cout << "!= " << (a != b) << std::endl;

	Fixed ten(10);
	Fixed five(5);
	std::cout << "math\n";
	std::cout << "- " << (ten - five) << std::endl;
	std::cout << "+ " << (ten + five) << std::endl;
	std::cout << "* " << (ten * five) << std::endl;
	std::cout << "/ " << (ten / five) << std::endl;
	return (0);
}

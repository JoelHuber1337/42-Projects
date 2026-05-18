/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:34:32 by johuber           #+#    #+#             */
/*   Updated: 2025/12/15 17:52:43 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class	Fixed
{
	private:
		int					fixedValue;
		static const int	bits = 8;
	public:
	Fixed();
	Fixed(const Fixed &a);
	Fixed(const int x);
	Fixed(const float num);
	~Fixed();
	Fixed& 					operator = (const Fixed &b);
	Fixed					operator + (const Fixed &b) const;
	Fixed					operator - (const Fixed &b) const;
	Fixed					operator * (const Fixed &b) const;
	Fixed					operator / (const Fixed &b) const;
	int						operator < (const Fixed &b) const;
	int						operator > (const Fixed &b) const;
	int						operator <= (const Fixed &b) const;
	int						operator >= (const Fixed &b) const;
	int						operator == (const Fixed &b) const;
	int						operator != (const Fixed &b) const;
	Fixed&					operator ++ ();
	Fixed					operator ++ (int);
	Fixed&					operator -- ();
	Fixed					operator -- (int);
	float					toFloat(void) const;
	int						toInt(void) const;
	void 					setRawBits(int const raw);
	int 					getRawBits(void) const;
	static Fixed			&min(Fixed &a, Fixed &b);
	static Fixed			&max(Fixed &a, Fixed &b);
	static const Fixed 		&min(Fixed const &a, Fixed const &b);
	static const Fixed		&max(Fixed const &a, Fixed const &b);
};

std::ostream&				operator << (std::ostream &out, const Fixed &b);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:34:32 by johuber           #+#    #+#             */
/*   Updated: 2025/12/14 21:37:57 by johuber          ###   ########.fr       */
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
	float					toFloat(void) const;
	int						toInt(void) const;
	void 					setRawBits(int const raw);
	int 					getRawBits(void) const;
};

std::ostream&				operator << (std::ostream &out, const Fixed &b);

#endif
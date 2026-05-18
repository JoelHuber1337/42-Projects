/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:34:32 by johuber           #+#    #+#             */
/*   Updated: 2025/12/14 16:16:46 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class	Fixed
{
	private:
		int					fixedValue;
		static const int	bits = 8;
	public:
	Fixed();
	Fixed(const Fixed &a);
	~Fixed();
	Fixed& 					operator = (const Fixed &b);
	void 					setRawBits(int const raw);
	int 					getRawBits(void) const;
};


#endif
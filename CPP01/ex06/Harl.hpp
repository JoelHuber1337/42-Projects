/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:37:48 by johuber           #+#    #+#             */
/*   Updated: 2025/12/10 19:42:17 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
# include <string>
# include <iostream>
# include <ctype.h>

class	Harl
{
	private:
		void 	debug(void) const;
		void 	info(void) const;
		void	warning(void) const;
		void	error(void) const;
	public:
		void	complain(std::string level);
};

#endif
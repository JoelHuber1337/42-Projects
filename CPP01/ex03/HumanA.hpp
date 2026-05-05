/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 23:37:13 by johuber           #+#    #+#             */
/*   Updated: 2025/12/05 18:28:56 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class	HumanA
{
	private:
	std::string	name;
	Weapon		&weapon;
	public:
	void		attack();
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
};

#endif
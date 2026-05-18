/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 23:37:13 by johuber           #+#    #+#             */
/*   Updated: 2025/12/05 17:42:31 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class	HumanB
{
	private:
	std::string	name;
	Weapon		*weapon;
	public:
	void		attack();
	HumanB(std::string name);
	HumanB();
	~HumanB();
	void		setWeapon(Weapon &weapon);
};

#endif
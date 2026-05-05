/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 23:37:04 by johuber           #+#    #+#             */
/*   Updated: 2025/12/05 18:29:40 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB() {}

HumanB::HumanB(std::string name)
{
	this->name = name;
}

HumanB::~HumanB() {}

void	HumanB::attack()
{
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void		HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
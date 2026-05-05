/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 19:28:55 by johuber           #+#    #+#             */
/*   Updated: 2025/12/17 21:41:39 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap Default Constructor has been called\n";
	this->name = "ScavTrap";
	this->hp = 100;
	this->ep = 50;
	this->ad = 20;
	this->guard = false;
	std::cout << "\033[0;38;2;187;161;79;49mScavTrap " << this->name << " has been created\033[0m\n";
}

ScavTrap::ScavTrap(const ScavTrap &clone) : ClapTrap(clone)
{
	std::cout << "ScavTrap Copy Constructor has been called\n";
	this->guard = clone.guard;
	std::cout << "\033[0;38;2;187;161;79;49mScavTrap " << this->name << " has been created\033[0m\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap Argument Constructor has been called\n";
	this->hp = 100;
	this->ep = 50;
	this->ad = 20;
	this->guard = false;
	std::cout << "\033[0;38;2;187;161;79;49mScavTrap " << name << " has been created\033[0m\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "Scavtrap Destructor called\n";
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->ep <= 0)
	{
		std::cout << "\033[31mScavTrap " << this->name << " does not have the Energy to attack\033[0m\n";
		return ;
	}
	if (this->hp <= 0)
	{
		std::cout << "\033[31mScavTrap " << this->name << " has been destroyed, it cannot attack\033[31m\n";
		return ;
	}
	std::cout << "ScavTrap " << this->name << " attacks " << target << " dealing \033[31m" << this->ad << " Damage\033[0m" << std::endl;
	if (this->ep != -2147483648)
		this->ep--;
}

void	ScavTrap::guardGate(void)
{
	if (this->guard)
	{
		std::cout << RED << "ScavTrap " << this->name << " is already in Gate keeper mode, exiting Gate Keeper mode\n" << RESET;
		this->guard = false;
		return ;
	}
	std::cout << GOLD << "ScavTrap " << this->name << " is now in Gate keeper mode\n" << RESET;
	this->guard = true;
}

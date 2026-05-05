/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 22:41:36 by johuber           #+#    #+#             */
/*   Updated: 2025/12/17 23:06:05 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap Default Constructor has been called\n";
	this->name = "FragTrap";
	this->hp = 100;
	this->ep = 100;
	this->ad = 30;
	std::cout << "\033[0;38;2;187;161;79;49mFragTrap " << this->name << " has been created\033[0m\n";
}

FragTrap::FragTrap(const FragTrap &clone) : ClapTrap(clone)
{
	std::cout << "FragTrap Copy Constructor has been called\n";
	std::cout << "\033[0;38;2;187;161;79;49mFragTrap " << this->name << " has been created\033[0m\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap Argument Constructor has been called\n";
	this->hp = 100;
	this->ep = 100;
	this->ad = 30;
	std::cout << "\033[0;38;2;187;161;79;49mFragTrap " << name << " has been created\033[0m\n";
}

FragTrap::~FragTrap()
{
	std::cout << "Fragtrap Destructor called\n";
}

void	FragTrap::attack(const std::string& target)
{
	if (this->ep <= 0)
	{
		std::cout << "\033[31mFragTrap " << this->name << " does not have the Energy to attack\033[0m\n";
		return ;
	}
	if (this->hp <= 0)
	{
		std::cout << "\033[31mFragTrap " << this->name << " has been destroyed, it cannot attack\033[31m\n";
		return ;
	}
	std::cout << "FragTrap " << this->name << " attacks " << target << " dealing \033[31m" << this->ad << " Damage\033[0m" << std::endl;
	if (this->ep != -2147483648)
		this->ep--;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << " requests a High Five!\n";
	std::cout << GREEN << "High Five accepted! :D\n" << RESET;
}

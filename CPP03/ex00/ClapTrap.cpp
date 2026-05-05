/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:15:56 by johuber           #+#    #+#             */
/*   Updated: 2025/12/17 17:07:42 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default Constructor has been called\n";
	this->name = "Claptrap";
	this->hp = 10;
	this->ep = 10;
	this->ad = 0;
}

ClapTrap::ClapTrap(const ClapTrap &clone)
{
	std::cout << "Copy Constructor has been called\n";
	*this = clone;
}

ClapTrap::ClapTrap(std::string	name)
{
	std::cout << "Argument Constructor has been called\n";
	this->name = name;
	this->hp = 10;
	this->ep = 10;
	this->ad = 0;
	std::cout << "ClapTrap " << name << " has been created\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->ep <= 0)
	{
		std::cout << "\033[31mClaptrap " << this->name << " does not have the Energy to attack\033[0m\n";
		return ;
	}
	if (this->hp <= 0)
	{
		std::cout << "\033[31mClaptrap " << this->name << " has been destroyed, it cannot attack\033[31m\n";
		return ;
	}
	std::cout << "Claptrap " << this->name << " attacks " << target << " dealing \033[31m" << this->ad << " Damage\033[0m" << std::endl;
	if (this->ep != -2147483648)
		this->ep--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= 2147483648 || this->hp - (int)amount > this->hp)
	{
		std::cout << "\033[31mClaptrap " << this->name << " would heal itself with this attack, attack was canceled\033[31m\n";
		return ;
	}
	if (this->hp <= 0)
	{
		std::cout << "Claptrap " << this->name << " has been destroyed, the dysfunctional body takes \033[31m" << amount << " Damage\033[0m\n";
		return ;
	}
	std::cout << "Claptrap " << this->name << " was hit for \033[31m" << amount << " Damage\033[0m" << std::endl;
	if (this->hp <= (int)amount)
		std::cout << "\033[31mClaptrap " << this->name << " has perished\033[0m" << std::endl;
	this->hp = hp - amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->ep <= 0)
	{
		std::cout << "\033[31mClaptrap " << this->name << " does not have the Energy to repair\033[0m\n";
		return ;
	}
	if (amount >= 2147483648)
	{
		std::cout << "\033[31mClaptrap " << this->name << " will not damage itself by repairing, repair canceled\033[31m\n";
		return ;
	}
	if (this->hp <= 0)
	{
		std::cout << "\033[31mClaptrap " << this->name << " has been destroyed, it cannot be repaired\033[0m\n";
		return ;
	}
	std::cout << "Claptrap " << this->name << " repaired itself for \033[32m" << amount << " HP\033[0m" << std::endl;
	this->hp = hp + amount;
	if (this->ep != -2147483648)
		this->ep--;
}

ClapTrap&	ClapTrap::operator = (const ClapTrap &b)
{
	std::cout << "Copy assignment Operator called\n";
	this->setName(b.getName());
	this->setAD(b.getAD());
	this->setEP(b.getEP());
	this->setHP(b.getHP());
	return (*this);
}

void	ClapTrap::setName(std::string name)
{
	this->name = name;
}

void	ClapTrap::setHP(int HP)
{
	this->hp = HP;	
}

void	ClapTrap::setEP(int EP)
{
	this->ep = EP;	
}

void	ClapTrap::setAD(int AD)
{
	this->ad = AD;	
}

std::string		ClapTrap::getName() const
{
	return (this->name);
}

int	ClapTrap::getHP() const
{
	return (this->hp);	
}

int	ClapTrap::getEP() const
{
	return (this->ep);
}

int	ClapTrap::getAD() const
{
	return (this->ad);
}
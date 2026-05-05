/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:37:44 by johuber           #+#    #+#             */
/*   Updated: 2025/12/10 19:35:37 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void 	Harl::debug(void) const
{
	std::cout << "[DEBUG] - I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do !\n" << std::endl;
}

void 	Harl::info(void) const
{
	std::cout << "[INFO] - I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger !\nIf you did, I wouldn’t be asking for more !\n" << std::endl;
}

void	Harl::warning(void)	const
{
		std::cout << "[WARNING] - I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void	Harl::error(void)	const
{
		std::cout << "[ERROR] - This is unacceptable !\nI want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	void (Harl::*fPtr[4])() const = 
	{ 
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error,
	};
	std::string		array[4] = {"debug", "info", "warning", "error"};
	for(int x = 0; x < 5; x++)
	{
		if (x == 4)
		{
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break ;
		}
		if (array[x] == level)
		{
			switch(x)
			{
				case (0):
					(this->*fPtr[0])();
				case (1):
					(this->*fPtr[1])();
				case (2):
					(this->*fPtr[2])();
				case (3):
					(this->*fPtr[3])();
			}
			break ;
		}
	}
}

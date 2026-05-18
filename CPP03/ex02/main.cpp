/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 20:22:22 by johuber           #+#    #+#             */
/*   Updated: 2025/12/17 23:09:31 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	// ClapTrap	robot;
	// ClapTrap	robot2("Peter");
	// ClapTrap	Robot3(robot);
	//ScavTrap	robot;
	//ScavTrap	robot2("Peter");
	//robot.guardGate();
	//ScavTrap	Robot3(robot);
	FragTrap	robot;
	FragTrap	robot2("Peter");
	FragTrap	Robot3(robot);

	robot.attack("Peter");
	robot2.takeDamage(9);
	robot2.beRepaired(10);
	robot2.attack("ClapTrap");
	robot.takeDamage(-10);
	robot.beRepaired(-1);
	for (int x = 0; x < 6; x++)
	{
		robot.attack("Peter");
		robot.beRepaired(1);
	}
	robot2.takeDamage(11);
	robot2.attack("ClapTrap");
	robot2.beRepaired(10);
	robot2.takeDamage(1);
	std::cout << "Copied Robot 3: \n" << "Name = " + Robot3.getName() + "\n" << "HP = " << Robot3.getHP() << "\n" << "EP = " << Robot3.getEP() << "\n" << "AD = " << Robot3.getAD() << std::endl;
	robot.highFivesGuys();
	// robot2.guardGate();
	// Robot3.guardGate();	
	// robot2.guardGate();
	// robot2.guardGate();
}

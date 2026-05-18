/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 20:18:50 by johuber           #+#    #+#             */
/*   Updated: 2025/12/11 15:32:41 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie *horde = zombieHorde(30, "Peter");
	Zombie *Chump;

	Chump = newZombie("Peter");
	Chump->announce();
	delete Chump;
	randomChump("john");
	for (int x = 0; x < 30; x++)
		(horde[x]).announce();
	delete[] horde;
}

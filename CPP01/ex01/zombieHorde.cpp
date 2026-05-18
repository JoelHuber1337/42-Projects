/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 22:03:44 by johuber           #+#    #+#             */
/*   Updated: 2025/12/11 15:15:40 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	int	X;

	X = 0;
	Zombie *return_zombie = new Zombie[N];
	while (X < N)
	{
		return_zombie[X].setName(name);
		X++;
	}
	return (return_zombie);
}

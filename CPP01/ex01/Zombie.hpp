/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 20:19:37 by johuber           #+#    #+#             */
/*   Updated: 2025/12/11 15:31:50 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define	ZOMBIE_HPP
# include <string>
# include <iostream>

class	Zombie
{
	private:
	std::string	name;
	public:
	void 	announce(void);
	void	setName(std::string name);
	Zombie();
	~Zombie();
};

void		randomChump(std::string name);
Zombie		*newZombie(std::string name);
Zombie* 	zombieHorde(int N, std::string name); 

#endif
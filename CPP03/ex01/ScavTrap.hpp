/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 19:28:40 by johuber           #+#    #+#             */
/*   Updated: 2025/12/17 20:54:59 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		bool	guard;
	public:
		ScavTrap();
		ScavTrap(const ScavTrap &clone);
		ScavTrap(std::string name);
		~ScavTrap();

		using	ClapTrap::operator =;
		void	attack(const std::string& target);
		void	guardGate(void);
};




#endif
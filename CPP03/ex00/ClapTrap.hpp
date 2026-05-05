/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:15:49 by johuber           #+#    #+#             */
/*   Updated: 2025/12/17 21:42:52 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <string>
# include <iostream>

class	ClapTrap
{
	private:
		std::string		name;
		int				hp;
		int				ep;
		int				ad;
	public:
		ClapTrap();
		ClapTrap(const ClapTrap &clone);
		ClapTrap(std::string name);
		~ClapTrap();

		ClapTrap& 		operator = (const ClapTrap &b);

		void			setName(std::string name);
		void			setHP(int HP);
		void			setEP(int EP);
		void			setAD(int AD);
		std::string		getName() const;
		int				getHP() const;
		int				getEP() const;
		int				getAD() const;
		void	 		attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void	 		beRepaired(unsigned int amount);
};


#endif
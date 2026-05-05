/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:15:49 by johuber           #+#    #+#             */
/*   Updated: 2025/12/17 17:44:07 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <string>
# include <iostream>
# define RED  "\033[31m"
# define GREEN "\033[32m"
# define GOLD "\033[0;38;2;187;161;79;49m"
# define RESET "\033[0m"

class	ClapTrap
{
	protected:
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
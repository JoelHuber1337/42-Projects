/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 20:30:41 by johuber           #+#    #+#             */
/*   Updated: 2025/12/23 19:40:23 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>
# include <iostream>

class	Animal
{
	protected:
		std::string 		type;
	public:
							Animal();
							Animal(std::string type);
							Animal(Animal &clone);
		virtual				~Animal();
		const std::string&	getType(void) const;
		void				setType(std::string type);
		Animal				&operator = (const Animal &b);
		virtual void		makeSound() const;
};

#endif
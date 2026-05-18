/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 20:30:21 by johuber           #+#    #+#             */
/*   Updated: 2025/12/23 19:18:35 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP
# include <string>
# include <iostream>

class	WrongAnimal
{
	protected:
		std::string 	type;
	public:
						WrongAnimal();
						WrongAnimal(std::string type);
						WrongAnimal(WrongAnimal &clone);
		virtual			~WrongAnimal();
		WrongAnimal			&operator = (const WrongAnimal &b);
		void			makeSound() const;
};





#endif
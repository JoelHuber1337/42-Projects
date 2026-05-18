/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 20:30:30 by johuber           #+#    #+#             */
/*   Updated: 2025/12/28 17:42:28 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"

class Dog : public Animal
{
	private:
					Brain	*brain;
	public:
					Dog();
					Dog(const Dog &d);
					~Dog();
		Dog&		operator = (const Dog &copy);
		Brain*		getBrain(void) const;
		void		makeSound(void) const;
};

#endif
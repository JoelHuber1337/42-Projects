/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 20:30:35 by johuber           #+#    #+#             */
/*   Updated: 2025/12/28 17:43:04 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"

class Cat : public Animal
{
	private:
					Brain	*brain;
	public:
					Cat();
					Cat(const Cat &d);
					~Cat();
		Cat&		operator = (const Cat &copy);
		Brain		*getBrain(void) const;
		void		makeSound(void) const;
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 19:54:38 by johuber           #+#    #+#             */
/*   Updated: 2025/12/23 20:26:01 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <string>
# include <iostream>

class	Brain
{
	private:
		std::string	ideas[100];		
	public:
		Brain();
		Brain(const Brain& clone);
		~Brain();
	Brain&				operator = (const Brain& copy);
	void				setIdea(std::string idea, int index);
	const std::string	getIdea(int index) const;
};


#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 19:54:01 by johuber           #+#    #+#             */
/*   Updated: 2025/12/28 17:38:03 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default Constructor called\n";
}

Brain::Brain(const Brain& clone)
{
	std::cout << "Brain Copy Constructor called\n";
	*this = clone;	
}

Brain::~Brain()
{
	std::cout << "Brain Deconstructor called\n";
}

Brain&	Brain::operator = (const Brain &copy)
{
	if (this == &copy)
		return (*this);
	for (int x = 0; x < 100; x++)
		this->ideas[x] = copy.ideas[x];
	return (*this);
	
}

void	Brain::setIdea(std::string idea, int index)
{
	if (index < 0 || index > 99)
		return ;
	this->ideas[index] = idea;
}

const std::string	Brain::getIdea(int index) const
{
	if (index < 0 || index > 99)
		return (NULL);
	return (this->ideas[index]);
}

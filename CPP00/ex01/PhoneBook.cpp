/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:44:06 by johuber           #+#    #+#             */
/*   Updated: 2025/12/03 17:46:54 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {}

PhoneBook::~PhoneBook(){}

void	PhoneBook::setContact(Contact &Con, int x)
{
	this->Contacts[x] = Con;
}

Contact	&PhoneBook::getContact(int x)
{
	return (this->Contacts[x]);
}

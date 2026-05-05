/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:44:24 by johuber           #+#    #+#             */
/*   Updated: 2025/12/05 20:17:00 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# include <iostream>
# include <string>
# include <iomanip>

class	PhoneBook
{
	private:
	Contact	Contacts[8];
	public:
	Contact	&getContact(int index);
	void	setContact(Contact &Con, int x);
	PhoneBook();
	~PhoneBook();
};

void	print_instructions();


#endif
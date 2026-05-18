/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:37:17 by johuber           #+#    #+#             */
/*   Updated: 2025/12/05 18:55:20 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include "PhoneBook.hpp"
# include <string>

class	Contact 
{
	private:
	std::string fname;
	std::string	lname;
	std::string	nname;
	std::string	phone_number;
	std::string	secret;
	public:
	std::string	getFname() const;
	std::string	getLname() const;
	std::string	getNname() const;
	std::string	getPnumber() const;
	std::string	getSecret() const;
	void		setPnumber(std::string &pnumber);
	void		setSecret(std::string &secret);
	void		setFname(std::string &res);
	void		setLname(std::string &lname);
	void		setNname(std::string &nname);
};

#endif
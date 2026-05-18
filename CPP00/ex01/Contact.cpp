/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:27:34 by johuber           #+#    #+#             */
/*   Updated: 2025/12/03 18:28:34 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string	Contact::getFname() const
{
	return(this->fname);
}

std::string	Contact::getLname() const
{
	return(this->lname);
}

std::string	Contact::getNname() const
{
	return(this->nname);
}

std::string	Contact::getPnumber() const
{
	return(this->phone_number);
}

std::string	Contact::getSecret() const
{
	return(this->secret);
}

void	Contact::setFname(std::string &res)
{
	this->fname = res;
}

void	Contact::setLname(std::string &res)
{
	this->lname = res;
}

void	Contact::setNname(std::string &res)
{
	this->nname = res;
}

void	Contact::setPnumber(std::string &res)
{
	this->phone_number = res;
}

void	Contact::setSecret(std::string &res)
{
	this->secret = res;
}
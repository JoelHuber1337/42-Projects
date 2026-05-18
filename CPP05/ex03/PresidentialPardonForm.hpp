/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 19:45:00 by marvin            #+#    #+#             */
/*   Updated: 2026/05/10 19:45:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "AForm.hpp"
# include <fstream>

class PresidentialPardonForm : public AForm
{
	private:
		std::string			target;
		virtual void		execDoc() const;
	public:
							PresidentialPardonForm();
							PresidentialPardonForm(std::string target);
							PresidentialPardonForm(const PresidentialPardonForm &cpy);
							~PresidentialPardonForm();
	std::string				getTarget() const;
	PresidentialPardonForm& 	operator = (const PresidentialPardonForm &cpy);
};

#endif
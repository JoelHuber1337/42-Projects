/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 19:45:27 by marvin            #+#    #+#             */
/*   Updated: 2026/05/10 19:45:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string			target;
		virtual void		execDoc() const;
	public:
							ShrubberyCreationForm();
							ShrubberyCreationForm(std::string target);
							ShrubberyCreationForm(const ShrubberyCreationForm &cpy);
							~ShrubberyCreationForm();
	std::string				getTarget() const;
	ShrubberyCreationForm& 	operator = (const ShrubberyCreationForm &cpy);

	class	OpenError : public std::exception
	{
		public:
			const char*		what() const throw();
	};
};

#endif
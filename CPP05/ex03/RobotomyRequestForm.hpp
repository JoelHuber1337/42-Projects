/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 19:45:22 by marvin            #+#    #+#             */
/*   Updated: 2026/05/10 19:45:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "AForm.hpp"
# include <fstream>

class RobotomyRequestForm : public AForm
{
	private:
		std::string			target;
		virtual void		execDoc() const;
	public:
							RobotomyRequestForm();
							RobotomyRequestForm(std::string target);
							RobotomyRequestForm(const RobotomyRequestForm &cpy);
							~RobotomyRequestForm();
	std::string				getTarget() const;
	RobotomyRequestForm& 	operator = (const RobotomyRequestForm &cpy);
};

#endif
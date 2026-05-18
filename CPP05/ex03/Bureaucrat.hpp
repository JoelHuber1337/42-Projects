/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:18:11 by johuber           #+#    #+#             */
/*   Updated: 2026/04/24 20:08:46 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include "AForm.hpp"
# include <iostream>
# include <string>
# include <exception>

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

class AForm;

class Bureaucrat
{
	private:
		const std::string 	name;
		int					grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &cpy);
		~Bureaucrat();
	
	Bureaucrat&				operator = (const Bureaucrat &cpy);

	std::string				getName() const;
	int						getGrade() const;
	void					incrementGrade(int plus = 1);
	void					decrementGrade(int minus = 1);
	void					signForm(AForm *document, bool error);
	void					executeForm(AForm const & form) const;
	class		GradeTooHighException : public std::exception
	{
		public:
			const char*		what() const throw();
	};
	class		GradeTooLowException : public std::exception
	{
		public:
			const char*		what() const throw();
	};
};

std::ostream&				operator << (std::ostream &out, const Bureaucrat &b);
	
#endif
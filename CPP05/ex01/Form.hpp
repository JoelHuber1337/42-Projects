/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:18:11 by johuber           #+#    #+#             */
/*   Updated: 2026/04/24 20:08:42 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"
# include <iostream>
# include <string>
# include <exception>
# include <cstdlib>

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

class Bureaucrat;

class Form
{
	private:
		const std::string 	name;
		bool				isSigned;
		const int			signGrade;
		const int			execGrade;
	public:
		Form();
		Form(std::string name, int signgrade, int execgrade);
		Form(const Form &cpy);
		~Form();
	
	Form&				operator = (const Form &cpy);

	std::string				getName() const;
	int						getSignGrade() const;
	int						getExecGrade() const;
	bool					getIsSigned() const;
	void					beSigned(Bureaucrat clerk);
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

std::ostream&				operator << (std::ostream &out, const Form &b);
	
#endif
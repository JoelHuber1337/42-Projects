/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:18:11 by johuber           #+#    #+#             */
/*   Updated: 2026/04/09 19:41:01 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <string>
# include <exception>

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

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
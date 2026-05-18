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

#ifndef AFORM_HPP
# define AFORM_HPP
# include "Bureaucrat.hpp"
# include <iostream>
# include <string>
# include <exception>
# include <cstdlib>

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

class Bureaucrat;

class AForm
{
	private:
		const std::string 	name;
		bool				isSigned;
		const int			signGrade;
		const int			execGrade;
		virtual void		execDoc() const = 0;
	public:
							AForm();
							AForm(std::string name, int signgrade, int execgrade);
							AForm(const AForm &cpy);
	virtual					~AForm() = 0;
	
	AForm&					operator = (const AForm &cpy);

	std::string				getName() const;
	int						getSignGrade() const;
	int						getExecGrade() const;
	bool					getIsSigned() const;
	void					beSigned(Bureaucrat clerk);
	void					execute(Bureaucrat const & executor) const;
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
	class		NotSigned : public std::exception
	{
		public:
			const char*		what() const throw();
	};
	class		LowExec : public std::exception
	{
		public:
			const char*		what() const throw();
	};
};

std::ostream&				operator << (std::ostream &out, const AForm &b);
	
#endif
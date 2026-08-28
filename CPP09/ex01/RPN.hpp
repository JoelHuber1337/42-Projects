/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 17:12:47 by marvin            #+#    #+#             */
/*   Updated: 2026/08/28 19:11:12 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <stack>
# include <list>
# include <iostream>
# include <algorithm>
# include <climits>
# include <fstream>
# include <sstream>

class RPN 
{
    private:
    std::stack<std::string, std::list<std::string> >     numbers;

        RPN();
        RPN (RPN &cpy);
        RPN& operator = (const RPN &cpy);
        
    public:
        RPN(std::stack<std::string, std::list<std::string> > &numbers);
        ~RPN();
    private:
    int                                                     checkToken(std::string token);
    std::string                                             plus(long a, long b);
    std::string                                             minus(long a, long b);
    std::string                                             multi(long a, long b);
    std::string                                             divide(long a, long b);
    void                                                    execute(long a, long b);
    void                                                    bExecute(long a, long b);
    std::string	                                            bottom();
    void    	                                            popBottom();
    class Error : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};



#endif
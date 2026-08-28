/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 13:20:57 by marvin            #+#    #+#             */
/*   Updated: 2026/08/28 19:17:26 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(std::stack<std::string, std::list<std::string> > &numbers)
{
	long	a;
	long	b;
	while (!numbers.size() != 1)
	{
		long a = atol(numbers.top().c_str());
		numbers.pop();
		long b = atol(numbers.top().c_str());
		numbers.pop();
		if (numbers.top() == "+")
		{
			numbers.pop();
			numbers.push(RPN::plus(a, b));
		}
		else if (numbers.top() == "-")
		{
			numbers.pop();
			numbers.push(RPN::minus(a, b));
		}
		else if (numbers.top() == "*")
		{
			numbers.pop();
			numbers.push(RPN::multi(a, b));
		}
		else if (numbers.top() == "/")
		{
			numbers.pop();
			numbers.push(RPN::divide(a, b));
		}
		else
		{
			std::cerr << "Error.\n";
			return ;
		}
	}
	std::cout << numbers.top() << std::endl;
}

RPN::RPN (RPN &cpy)
{
	(void)cpy;
}

RPN::~RPN() {}

RPN& RPN::operator=(const RPN &cpy)
{
	(void)cpy;
	return (*this);
}

std::string	plus(long a, long b)
{
	long				res;
	std::stringstream	stream;
	std::string			str;

	if (a > INT_MAX || b > INT_MAX)
		//throw_error	
	res = a + b;
	stream << res;
	str = stream.str();
	return (str);
}

    std::string                                             minus(long a, long b);
    std::string                                             multi(long a, long b);
    std::string                                             divide(long a, long b);
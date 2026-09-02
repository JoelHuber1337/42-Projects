/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 13:20:57 by marvin            #+#    #+#             */
/*   Updated: 2026/09/01 20:46:50 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(std::stack<std::string, std::list<std::string> > &numbers)
{
	this->numbers = numbers;

	while (this->numbers.size() != 1)
	{
		long a = atol(this->numbers.top().c_str());
		if (a == 0 && this->numbers.top() != "0")
		{
			std::cerr << "Error.\n";
			return ;
		}
		this->numbers.pop();
		long b = atol(this->numbers.top().c_str());
		if (b == 0 && this->numbers.top() != "0")
		{
			std::cerr << "Error.\n";
			return ;
		}
		this->numbers.pop();
		if (this->numbers.empty())
		{
			std::cerr << "Error.\n";
			return ;
		}
		if (isdigit(this->numbers.top()[0]) && this->numbers.size() > 1)
			b = prioExec(b);
		if (checkToken(this->numbers.top()))
			execute(a, b);
		else if (checkToken(bottom()))
			bExecute(a, b);
		else
		{
			std::cerr << "Error.\n";
			return ;
		}
	}
	if (isdigit(this->numbers.top()[0]))
		std::cout << this->numbers.top() << std::endl;
	else
		std::cerr << "Error.\n";
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

int	RPN::checkToken(std::string token)
{
	if (token == "+" || token == "-" || token == "*" || token == "/")
		return (1);
	return (0);
}

long	RPN::prioExec(long b)
{
	long c = atol(this->numbers.top().c_str());
	this->numbers.pop();
	if (!checkToken(this->numbers.top()))
		throw Error();
	if (this->numbers.top() == "+")
	{
		this->numbers.pop();
		return (atol(RPN::plus(b, c).c_str()));
	}
	else if (this->numbers.top() == "-")
	{
		this->numbers.pop();
		return(atol(RPN::minus(b, c).c_str()));
	}
	else if (this->numbers.top() == "*")
	{
		this->numbers.pop();
		return(atol(RPN::multi(b, c).c_str()));
	}
	else if (this->numbers.top() == "/")
	{
		this->numbers.pop();
		return(atol(RPN::divide(b, c).c_str()));
	}
	throw Error();
}

void	RPN::execute(long a, long b)
{
	if (this->numbers.top() == "+")
	{
		this->numbers.pop();
		this->numbers.push(RPN::plus(a, b));
	}
	else if (this->numbers.top() == "-")
	{
		this->numbers.pop();
		this->numbers.push(RPN::minus(a, b));
	}
	else if (this->numbers.top() == "*")
	{
		this->numbers.pop();
		this->numbers.push(RPN::multi(a, b));
	}
	else if (this->numbers.top() == "/")
	{
		this->numbers.pop();
		this->numbers.push(RPN::divide(a, b));
	}
}

void	RPN::bExecute(long a, long b)
{
	if (bottom() == "+")
	{
		popBottom();
		numbers.push(RPN::plus(a, b));
	}
	else if (bottom() == "-")
	{
		popBottom();
		numbers.push(RPN::minus(a, b));
	}
	else if (bottom() == "*")
	{
		popBottom();
		numbers.push(RPN::multi(a, b));
	}
	else if (bottom() == "/")
	{
		popBottom();
		numbers.push(RPN::divide(a, b));
	}
}

std::string	RPN::plus(long a, long b)
{
	long				res;
	std::stringstream	stream;
	std::string			str;

	res = a + b;
	if (res > INT_MAX)
		throw Error();
	stream << res;
	str = stream.str();
	return (str);
}

std::string	RPN::minus(long a, long b)
{
	long				res;
	std::stringstream	stream;
	std::string			str;

	res = a - b;
	if (res < 0)
		throw Error();
	stream << res;
	str = stream.str();
	return (str);
}

std::string	RPN::multi(long a, long b)
{
	long				res;
	std::stringstream	stream;
	std::string			str;

	res = a * b;
	if (res > INT_MAX)
		throw Error();
	stream << res;
	str = stream.str();
	return (str);
}

std::string	RPN::divide(long a, long b)
{
	long				res;
	std::stringstream	stream;
	std::string			str;

	if (b == 0)
		throw Error();
	res = a / b;
	stream << res;
	str = stream.str();
	return (str);
}

void	RPN::popBottom()
{
	std::stack<std::string, std::list<std::string> > tmp;

	while (this->numbers.size() > 1)
	{
		tmp.push(this->numbers.top());
		this->numbers.pop();
	}
	this->numbers.pop();
	while (!tmp.empty())
	{
		this->numbers.push(tmp.top());
		tmp.pop();
	}
}

std::string	RPN::bottom()
{
	std::stack<std::string, std::list<std::string> > tNumbers = this->numbers;
	while (tNumbers.size() != 1)
		tNumbers.pop();
	return (tNumbers.top());
}

const char *RPN::Error::what() const throw()
{
	return ("Error.\n");
}
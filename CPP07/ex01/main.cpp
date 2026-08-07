/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 15:39:10 by johuber           #+#    #+#             */
/*   Updated: 2026/08/07 19:17:27 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	testprint(int x)
{
	std::cout << x << "\n";
}

int	main()
{
	int					d[] = {5, 6, 7, 8};
	const int			cd[] = {5, 6, 7, 8};
	::iter(d, 4, testprint);
	::iter(cd, 4, testprint);
	/*
	int					d[] = {5, 6, 7, 8};
	const int			cd[] = {5, 6, 7, 8};
	char				c[] = {'a', 'b', 'c', 'd', 'e', 'f'};
	const char			cc[] = {'a', 'b', 'c', 'd', 'e', 'f'};
	std::string			str[] = {"hey", "I", "love", "42"};
	const std::string	cstr[] = {"hey", "I", "love", "42"};

	std::cout << "Testing my function template, first test, two int arrays with: 5 6 7 8.\n";
	std::cout << "The second array is a const array, testing functionality with both normal and const values.\n";
	std::cout << "The provided function is a print function that prints every int. It is an instantiated function template\n";
	::iter(d, 4, testprint<int>);
	::iter(cd, 4, testprint<const int>);
	std::cout << "-----------------------------------------------------------------------------------------------------------\n";
	std::cout << "Now testing with char arrays: a b c d e f\n";
	::iter(c, 6, testprint<char>);
	::iter(cc, 6, testprint<const char>);
	std::cout << "-----------------------------------------------------------------------------------------------------------\n";
	std::cout << "Now testing with string arrays: hey I love 42\n";
	::iter(str, 4, testprint<std::string>);
	::iter(cstr, 4, testprint<const std::string>);
	*/
}
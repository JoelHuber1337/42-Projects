/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 16:06:20 by johuber           #+#    #+#             */
/*   Updated: 2026/09/01 15:36:25 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	inputChecks(std::string str)
{
	if (str.length() == 0 || str.length() > 10)
		return (1);
	for (int x = 0; str[x]; x++)
		if (!isdigit(str[x]))
			return (std::cerr << "Error\n", 1);
	long	res = atol(str.c_str());
	if (res == 0 && str[0] != '0')
		return (std::cerr << "Error\n", 1);
	if (res < 0 || res > INT_MAX)
		return (std::cerr << "Error\n", 1);
	return (0);
}

int main (int ac, char **av)
{
	if (ac < 2)
		return (std::cerr << "Error\n", 1);
	for (int x = 1; av[x]; x++)
		if (inputChecks(av[x]))
			return (1);
	vecDataManagment(av);
	
}
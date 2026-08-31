/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 13:20:57 by marvin            #+#    #+#             */
/*   Updated: 2026/08/31 19:06:07 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <unistd.h>

void	vecDataManagment(char **str)
{
	std::clock_t		start = std::clock();
	std::vector<int>	vec;
	
	std::cout << "Before:\t"; 
	for (int x = 1; str[x]; x++)
	{
		std::cout << atoi(str[x]);
		vec.push_back(atoi(str[x]));
		if (str[x + 1])
			std::cout << " ";
	}
	std::cout << "\n";
	//algorithm();
	std::cout << "After:\t";
	for (std::vector<int>::iterator	it = vec.begin(); it != vec.end(); it++)
	{
		std::cout << *it;
		if (it != vec.end() - 1)
			std::cout << " ";
	}
	std::cout << "\n";
	std::clock_t	end = std::clock();
	std::cout << "Time to process a range of " << vec.size() <<  " elements with std:vector : " << std::fixed << std::setprecision(6) << static_cast<double>(end - start) / CLOCKS_PER_SEC << " us \n";
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 13:20:57 by marvin            #+#    #+#             */
/*   Updated: 2026/09/02 18:05:30 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <unistd.h>

void	vecRecSplitSort(std::vector<pair> &pairs)
{
	std::vector<pair>	tmp;
	
	for (size_t x = 0; x + 1 < pairs.size(); x += 2)
	{
		pair	res;
		if (pairs[x].larger > pairs[x + 1].larger)
		{
			res.larger = (pairs[x]).larger;
			res.smaller = (pairs[x]).smaller;
			pairs.erase(pairs.begin() + x);
		}
		else
		{
			res.larger = (pairs[x + 1]).larger;
			res.smaller = (pairs[x + 1]).smaller;
			pairs.erase(pairs.begin() + x + 1);
		}
		tmp.push_back(res);
	}
	if (pairs.size() > 1)
		vecRecSplitSort(pairs);
	if (tmp.size() > 1)
		vecRecSplitSort(pairs);
	std::cout << "tmp ->" << tmp[0].larger << "\n";
	std::cout << "pairs ->" << pairs[0].larger << "\n";
}

void	vecAlgo(std::vector<int> &vec)
{
	std::vector<pair>	pairs;
	bool				isLast = vec.size() % 2 != 0;
	int					last = 0;

	for (size_t x = 0; x + 1 < vec.size(); x += 2)
	{
		pair	res;
	
		if (vec[x] > vec[x + 1])
		{
			res.larger = vec[x];
			res.smaller = vec[x + 1];
		}
		else
		{
			res.smaller = vec[x];
			res.larger = vec[x + 1];
		}
		pairs.push_back(res);
	}
	if (isLast)
		last = vec.back();
	if (pairs.size() > 1)
		vecRecSplitSort(pairs);
}

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
	vecAlgo(vec);
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
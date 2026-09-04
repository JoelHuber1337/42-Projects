/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 13:20:57 by marvin            #+#    #+#             */
/*   Updated: 2026/09/04 19:14:09 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <unistd.h>

void	vecSwap(std::vector<int> &vec, int start, int end)
{
	std::vector<int>	tmp;
	std::vector<int>	tmp2;
	int 				x = 0;

	while (x + start < end)
	{
		tmp.push_back(vec[x + start]);
		x++;
	}
	x = 0;
	while (x + start < end)
	{
		tmp2.push_back(vec[x + end]);
		vec[x + end] = tmp[x];
		x++;
	}
	x = 0;
	while (x + start < end)
	{
		vec[x + start] = tmp2[x];
		x++;
	}
}

int	deqIsSmaller(int x, int y)
{
	deqCount++;
	if (x < y)
		return (1);
	return (0);
}

int	vecIsSmaller(int x, int y)
{
	vecCount++;
	if (x < y)
		return (1);
	return (0);
}

void	vecRecSplitSort(std::vector<pair> pairs, std::vector<pair> &res)
{
	std::vector<pair>	tmp;
	
	for (size_t x = 0; x + 1 < pairs.size(); x++)
	{
		pair	res;
		if (pairs[x].larger < pairs[x + 1].larger)
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
		vecRecSplitSort(pairs, res);
	if (tmp.size() > 1)
		vecRecSplitSort(tmp, res);
	
	std::cout << "pairs ->" << pairs[0].larger << "\n";
	std::cout << "tmp ->" << tmp[0].larger << "\n";
	res.push_back(pairs[0]);
}

std::vector<int>	vecAlgo(std::vector<int> vec, int Flevel)
{
	if (vec.size() == 1)
		return (vec);
	bool				isLast = vec.size() % 2 != 0;
	int					last = 0;
	int					level = pow(2, Flevel);

	for (size_t x = 0; x + (level * 2) < vec.size() - (level * isLast); x += 2 * level)
	{
	
		if (vecIsSmaller(vec[x], vec[x + level]))
			vecSwap(vec, x, x + level);
	}
	if (isLast)
		last = vec.back();
	(void)last;
	for (size_t x = 0; x < pairs.size(); x++)
		std::cout << "Pairs -> " << pairs[x].larger << "\n" << pairs[x].smaller << "\n";
	if (pairs.size() > 1)
		vecRecSplitSort(pairs, res);
	std::cout << pairs.size() << "\n";
	for (size_t x = 0; x < res.size(); x++)
		std::cout << "Res -> " << res[x].larger << " " << res[x].smaller << "\n";
}

void	vecDataManagment(char **str)
{
	std::clock_t		start = std::clock();
	std::vector<int>	vec;
	std::deque<int>		deq;
	
	std::cout << "Before:\t"; 
	for (int x = 1; str[x]; x++)
	{
		std::cout << atoi(str[x]);
		vec.push_back(atoi(str[x]));
		if (str[x + 1])
			std::cout << " ";
	}
	std::cout << "\n";
	vecAlgo(vec, 0);
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
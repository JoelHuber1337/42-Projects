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
/*
std::vector<int>	vecAlgo(std::vector<int> vec)
{
	if (vec.size() < 2)
		return (vec);
	int					isLast = vec.size() % 2 != 0;
	//int					last = 0;

	if (isLast)
	{
		//last = vec.back();
		vec.pop_back();
	}
	std::vector<int>	biggers(vec.size() / 2);
	std::vector<losers>	smallers(vec.size() / 2);

	for (size_t x = 0; x + 1 < vec.size(); x += 2 )
	{
	
		if (vecIsSmaller(vec[x], vec[x + 1]))
		{
			biggers[x / 2] = vec[x + 1];
			losers	tmp = {vec[x], x / 2};
			smallers[x / 2] = tmp;
		}
		else
		{
			biggers[x / 2] = vec[x];
			losers	tmp = {vec[x + 1], x / 2};
			smallers[x / 2] = tmp;
		}
	}
	std::vector<int>	mainChain = vecAlgo(biggers);
	mainChain.insert(mainChain.begin(), smallers[smallers[0].id].value);
	for (size_t z = 0; z < smallers.size(); z++)
    {
        if (smallers[z].id >= 0)
            smallers[z].id++;
	}	
	std::vector<size_t>	jacobNums;
	jacobNums.push_back(1);
	jacobNums.push_back(1);
	while (jacobNums.back() < vec.size() / 2 + isLast)
		jacobNums.push_back(jacobNums[jacobNums.size() - 1] + 2 * jacobNums[jacobNums.size() - 2]);

	for (size_t x = 2; x < jacobNums.size(); x++)
	{
  		size_t current = jacobNums[x];

  		if (current > smallers.size())
  	    	current = smallers.size();

    	size_t previous = jacobNums[x - 1];

    	if (previous > smallers.size())
        	previous = smallers.size();

    // Insert losers in reverse order:
    // e.g. 3, 2 then 5, 4 then 11, 10, 9...
    	for (size_t y = current; y > previous; y--)
    	{
        	size_t loserIndex = y - 1;
        	losers loser = smallers[loserIndex];

        // The bigger partner is currently at loser.id.
        // We only search before that bigger.
        	size_t left = 0;
        	size_t right = loser.id;

        	while (left < right)
        	{
            	size_t middle = left + (right - left) / 2;

            	if (vecIsSmaller(mainChain[middle], loser.value))
                	left = middle + 1;
            	else
                	right = middle;
        	}

        	size_t insertPos = left;

        	mainChain.insert(mainChain.begin() + insertPos, loser.value);

        // Everything at or after insertPos shifted one position right.
        	for (size_t z = 0; z < smallers.size(); z++)
        	{
            	if (smallers[z].id >= insertPos)
                	smallers[z].id++;
        	}
    	}
	}
	return (mainChain);
}
*/

struct losers
{
	bool	hasPartner;
    int     value;
    size_t  id;
    size_t  origin;
};

struct SortResult
{
    std::vector<int>    values;
    std::vector<size_t> origin;
};


SortResult vecAlgoRec(std::vector<int> vec)
{
    if (vec.size() <= 1)
    {
        SortResult result;
        result.values.push_back(vec[0]);
        result.origin.push_back(0);
        return result;
    }
    bool isLast = (vec.size() % 2 != 0);
    int last = 0;
    size_t lastOrigin = 0;

    if (isLast)
    {
        last = vec.back();
        lastOrigin = vec.size() - 1;
        vec.pop_back();
    }
    size_t pairCount = vec.size() / 2;
    std::vector<int> biggers(pairCount);
    std::vector<size_t> biggerOrigin(pairCount);
    std::vector<losers> smallers(pairCount);

    for (size_t x = 0; x < vec.size(); x += 2)
    {
        size_t i = x / 2;

        if (vecIsSmaller(vec[x], vec[x + 1]))
        {
            biggers[i] = vec[x + 1];
            biggerOrigin[i] = x + 1;

            smallers[i].value = vec[x];
            smallers[i].id = i;
            smallers[i].origin = x;
			smallers[i].hasPartner = true;
        }
        else
        {
            biggers[i] = vec[x];
            biggerOrigin[i] = x;

            smallers[i].value = vec[x + 1];
            smallers[i].id = i;
            smallers[i].origin = x + 1;
			smallers[i].hasPartner = true;
        }
    }
    SortResult sorted = vecAlgoRec(biggers);
    std::vector<int> mainChain = sorted.values;
    std::vector<size_t> mainOrigin(pairCount);
    std::vector<losers> orderedSmallers(pairCount);

    for (size_t i = 0; i < sorted.origin.size(); i++)
    {
        mainOrigin[i] = biggerOrigin[sorted.origin[i]];
        orderedSmallers[i] = smallers[sorted.origin[i]];
    }
    smallers = orderedSmallers;
    for (size_t i = 0; i < smallers.size(); i++)
        smallers[i].id = i;
    if (isLast)
    {
        losers tmp;

        tmp.value = last;
        tmp.id = 0;
		tmp.hasPartner = false;
        tmp.origin = lastOrigin;

        smallers.push_back(tmp);
    }
    mainChain.insert(mainChain.begin(), smallers[0].value);
    mainOrigin.insert(mainOrigin.begin(), smallers[0].origin);
    for (size_t i = 0; i < smallers.size(); i++)
            smallers[i].id++;
    std::vector<size_t> jacobNums;
    jacobNums.push_back(1);
    jacobNums.push_back(1);
    while (jacobNums.back() < smallers.size())
        jacobNums.push_back(jacobNums[jacobNums.size() - 1] + 2 * jacobNums[jacobNums.size() - 2]);
    for (size_t x = 2; x < jacobNums.size(); x++)
    {
        size_t current = jacobNums[x];
        if (current > smallers.size())
            current = smallers.size();

        size_t previous = jacobNums[x - 1];
        if (previous > smallers.size())
            previous = smallers.size();
        for (size_t y = current; y > previous; y--)
        {
            size_t loserIndex = y - 1;
            losers loser = smallers[loserIndex];

            size_t left = 0;
            size_t right;
            if (loser.hasPartner)
                right = loser.id;
            else
				right = mainChain.size();
            while (left < right)
            {
                size_t middle = left + (right - left) / 2;

                if (vecIsSmaller(mainChain[middle], loser.value))
                    left = middle + 1;
                else
                    right = middle;
            }
            size_t insertPos = left;
            mainChain.insert(mainChain.begin() + insertPos, loser.value);
            mainOrigin.insert(mainOrigin.begin() + insertPos, loser.origin);
            for (size_t z = 0; z < smallers.size(); z++)
            {
                if (smallers[z].id >= insertPos)
                    smallers[z].id++;
            }
        }
    }
	SortResult res;
	res.origin = mainOrigin;
	res.values = mainChain;
    return (res);
}


/*
 * Public interface used by the rest of your program.
 */
std::vector<int> vecAlgo(std::vector<int> vec)
{
    SortResult result = vecAlgoRec(vec);
    return result.values;
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
	vec = vecAlgo(vec);
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
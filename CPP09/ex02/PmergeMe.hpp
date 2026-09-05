/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 17:12:47 by marvin            #+#    #+#             */
/*   Updated: 2026/09/04 18:05:04 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <deque>
# include <vector>
# include <iostream>
# include <algorithm>
# include <climits>
# include <fstream>
# include <sstream>
# include <ctime>
# include <iomanip>
# include <utility>
# include <cmath>

extern int	deqCount;
extern int	vecCount;

struct losers
{
	int value;
	size_t id;
};

void						vecDataManagment(char **str);

#endif
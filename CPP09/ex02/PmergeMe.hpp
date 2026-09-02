/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 17:12:47 by marvin            #+#    #+#             */
/*   Updated: 2026/09/02 17:26:03 by johuber          ###   ########.fr       */
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

struct pair
{
	int larger;
	int smaller;
};

void						vecDataManagment(char **str);

#endif
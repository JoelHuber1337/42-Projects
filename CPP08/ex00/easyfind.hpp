/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 17:12:47 by marvin            #+#    #+#             */
/*   Updated: 2026/08/07 19:23:35 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <vector>
# include <iostream>
# include <algorithm>
# include <deque>
# include <list>

template<typename T>
int easyfind(T &con, int x)
{
    typename T::iterator    res;

    res = std::find(con.begin(), con.end(), x);
    if (res == con.end())
        return (-1);
    return (std::distance(con.begin(), res));
}

#endif
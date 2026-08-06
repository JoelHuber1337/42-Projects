/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 17:12:47 by marvin            #+#    #+#             */
/*   Updated: 2026/08/04 17:12:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP
# include <iostream>

template<typename T>
void    swap(T &x, T &y)
{
    T   temp;

    temp = x;
    x = y;
    y = temp;
}

template<typename T>
T   min(T x, T y)
{
    if (x < y)
        return (x);
    return (y);
}

template<typename T>
T   max(T x, T y)
{
    if (x > y)
        return (x);
    return (y);
}


#endif
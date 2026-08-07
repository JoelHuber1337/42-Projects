/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 17:12:47 by marvin            #+#    #+#             */
/*   Updated: 2026/08/07 19:15:29 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>
/*
template<typename T>
void	testprint(T data)
{
	std::cout << data << "\n";
}


template<typename T>
void	testprint(const T data)
{
	std::cout << data << "\n";
}
*/

template<typename T, typename TF>
void	iter(T *arr, const int len, TF func)
{
	for (int x = 0; x < len; x++)
		func(arr[x]);
}

template<typename T, typename TF>
void	iter(const T *arr, const int len, TF func)
{
	for (int x = 0; x < len; x++)
		func(arr[x]);
}

#endif
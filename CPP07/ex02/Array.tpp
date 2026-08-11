/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 17:05:08 by marvin            #+#    #+#             */
/*   Updated: 2026/08/10 17:05:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP
# include "Array.hpp"

//We should create an empty array here, is this correct?
template<typename T>
Array<T>::Array()
{
    this->arr = NULL;
    this->len = 0;
}

template<typename T>
Array<T>::Array(unsigned int n)
{
    this->arr = new T[n];
    this->len = n;
}

template<typename T>
Array<T>::Array(const Array &cpy)
{
    this->arr = new T[cpy.len];
    for (unsigned int x = 0; x < cpy.len; x++)
        this->arr[x] = cpy.arr[x];
    this->len = cpy.len;
}

template<typename T>
Array<T>::~Array()
{
    delete [] this->arr;
}

template<typename T>
Array<T>&    Array<T>::operator = (const Array &cpy)
{
	if (this == &cpy)
		return (*this);
    this->arr = new T[cpy.len] ;
    for (unsigned int x = 0; x < cpy.len; x++)
        this->arr[x] = cpy.arr[x];
    return (*this);
}

template<typename T>
T&  Array<T>::operator[](unsigned int x)
{
    if (x >= this->len)
        throw (NoAcessException());
    return (this->arr[x]);
}

template<typename T>
const T&             Array<T>::operator[](unsigned int x) const
{
    if (x >= this->len)
        throw (NoAcessException());
    return (this->arr[x]);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (this->len);
}


template <typename T>
const char *Array<T>::NoAcessException::what() const throw()
{
	return ("Out of bounds");
}

#endif
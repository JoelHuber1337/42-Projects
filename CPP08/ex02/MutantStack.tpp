/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 20:26:40 by marvin            #+#    #+#             */
/*   Updated: 2026/08/14 20:26:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &cpy) : std::stack<T>(cpy)
{}

template <typename T>
MutantStack<T>::~MutantStack()
{}

template <typename T>
MutantStack<T>&                 MutantStack<T>::operator = (const MutantStack &cpy)
{
    if (this == &cpy)
        return (*this);
    *this = std::stack<T>::operator=(cpy);
    return (*this);
}

template <typename T>
typename MutantStack<T>::iterator    MutantStack<T>::begin()
{
    return (std::stack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::iterator   MutantStack<T>::end()
{
    return (std::stack<T>::c.end());
}
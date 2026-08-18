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

#include "Span.hpp"

Span::Span()
{
    this->N = 0;
}

Span::Span(unsigned int N)
{
    this->N = N;
}

Span::Span(const Span &cpy)
{
    *this = cpy;
}

Span::~Span() {}

Span&    Span::operator=(const Span &cpy)
{
    if (this == &cpy)
        return (*this);
    this->N = cpy.N;
    this->vec = cpy.vec;
    return (*this);
}

void    Span::addNumber(int num)
{
    if (this->vec.size() >= this->N)
        throw (VectorIsFull());
    this->vec.push_back(num);
}

void    Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (this->vec.size() + std::distance(begin, end) > this->N)
        throw (VectorIsFull());
    this->vec.insert(this->vec.end(), begin, end);
}

int Span::shortestSpan()
{
    if (this->vec.size() <= 1)
        throw (VectorIsTooSmall());
    Span    cpy(*this);
    int     res = INT_MAX;
    int     min = 0;

    std::sort(cpy.vec.begin(), cpy.vec.end());
    for (size_t x = 1; x < cpy.vec.size(); x++)
    {
        min = std::abs(cpy.vec[x] - cpy.vec[x - 1]);
        if (res > min)
            res = min;         
    }
    return (res);
}

int Span::longestSpan()
{
    std::vector<int>::iterator  max;
    std::vector<int>::iterator  min;

    if (this->vec.size() <= 1)
        throw (VectorIsTooSmall());
    max = std::max_element(this->vec.begin(), this->vec.end());
    min = std::min_element(this->vec.begin(), this->vec.end());
    return (*max - *min);
}

const char *Span::VectorIsFull::what() const throw()
{
	return ("The Vector cannot hold anymore Numbers");
}

const char *Span::VectorIsTooSmall::what() const throw()
{
	return ("There are not enough Numbers to create a span");
}
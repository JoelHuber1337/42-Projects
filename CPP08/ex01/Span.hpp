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

#ifndef SPAN_HPP
# define SPAN_HPP
# include <vector>
# include <iostream>
# include <algorithm>
# include <exception>
# include <climits>
# include <time.h>

class   Span
{
    private:
        unsigned int            N;
        std::vector<int>        vec;
    public:
                                Span();
                                Span(unsigned int N);
                                Span(const Span &cpy);
                                ~Span();
    Span                        &operator = (const Span &cpy);
    void                        addNumber(int num);
    void                        addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    int                         shortestSpan();
    int                         longestSpan();

    class VectorIsFull : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class VectorIsTooSmall : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

#endif
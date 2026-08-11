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

#ifndef Array_HPP
# define Array_HPP
# include <iostream>
# include <exception>

template<typename T>
class  Array
{
        private:
            T               *arr;
            unsigned int    len;
    public:
                            Array();
                            Array(unsigned int len);
                            Array(const Array &cpy);
                            ~Array();
        Array<T>            &operator = (const Array &cpy);
		T                   &operator[](unsigned int x);
		T const             &operator[](unsigned int x) const;
        unsigned int        size() const;
		class NoAcessException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

# include "Array.tpp"

#endif
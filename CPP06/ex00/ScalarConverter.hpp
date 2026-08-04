/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 20:05:33 by marvin            #+#    #+#             */
/*   Updated: 2026/05/27 20:05:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
# include <iostream>
# include <limits>
# include <string>
# include <stdlib.h>
# include <iomanip>

# define MIN_INT std::numeric_limits<int>::min()
# define MAX_INT std::numeric_limits<int>::max()
# define MIN_FLOAT std::numeric_limits<float>::min()
# define MAX_FLOAT std::numeric_limits<float>::max()
# define MIN_DOUBLE std::numeric_limits<double>::min()
# define MAX_DOUBLE std::numeric_limits<double>::max()

class   ScalarConverter
{
    private:
                        ScalarConverter();
                        ScalarConverter(ScalarConverter const &cpy);
                        ~ScalarConverter();
                        ScalarConverter &operator=(ScalarConverter const &cpy);
    public:
        static void     convert(const std::string &string);
};

#endif
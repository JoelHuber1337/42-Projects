/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 20:38:20 by marvin            #+#    #+#             */
/*   Updated: 2026/05/26 20:38:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int arc, char **arv)
{
    if (arc < 2)
    {
        std::cout << "Please enter one value, such as a char, int, float or double" << std::endl;
        return (1);
    }
    else if (arc > 2)
    {
        std::cout << "Please enter ONE value, such as a char, int, float or double" << std::endl;
        return (1);
    }
    ScalarConverter::convert(arv[1]);
    return (0);
}
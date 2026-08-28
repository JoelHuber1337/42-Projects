/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 13:21:03 by marvin            #+#    #+#             */
/*   Updated: 2026/08/28 13:21:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main (int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error.\n";
        return (1);
    }
    std::stack<int, std::list <int>>    number;

    RPN    calc(number);

    return (0);
}
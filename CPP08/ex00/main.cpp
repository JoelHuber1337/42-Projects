/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 15:26:45 by marvin            #+#    #+#             */
/*   Updated: 2026/08/26 14:13:10 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
    std::vector<int>    v;
    std::deque<int>     de;
    std::list<int>      l;

    for (int x = 0; x < 5; x++)
        v.push_back(x + 42);
    std::cout << easyfind(v, 42) << "\n";
    std::cout << easyfind(v, 43) << "\n";
    std::cout << easyfind(v, 44) << "\n";
    std::cout << easyfind(v, 0) << "\n";
    for (int x = 0; x < 5; x++)
        de.push_back(x + 42);
    std::cout << easyfind(de, 42) << "\n";
    std::cout << easyfind(de, 43) << "\n";
    std::cout << easyfind(de, 44) << "\n";
    std::cout << easyfind(de, 0) << "\n";
    for (int x = 0; x < 5; x++)
        l.push_back(x + 42);
    std::cout << easyfind(l, 42) << "\n";
    std::cout << easyfind(l, 43) << "\n";
    std::cout << easyfind(l, 44) << "\n";
    std::cout << easyfind(l, 0) << "\n";
}
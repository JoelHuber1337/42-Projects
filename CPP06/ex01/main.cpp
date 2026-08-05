/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 18:34:41 by marvin            #+#    #+#             */
/*   Updated: 2026/08/04 18:34:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    Data         *ptr = new Data;
    ptr->author = "Franz Kafka";
    ptr->page = 1;
    ptr->poem = "Eines Tages erwachte Gregor Samsa als ein Insekt";

    std::cout << "Before Serialization: \n";
    std::cout << ptr->page << "\n";
    std::cout << ptr->author << "\n";
    std::cout << ptr->poem << "\n";
    std::cout << "-----------------------------------\n";
    uintptr_t   i = Serializer::serialize(ptr);
    Data        *res = Serializer::deserialize(i);
    std::cout << "After Serialization: \n";
    std::cout << res->page << "\n";
    std::cout << res->author << "\n";
    std::cout << res->poem << std::endl;
    delete ptr;
    return (0);
}

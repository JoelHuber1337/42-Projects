/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 15:26:45 by marvin            #+#    #+#             */
/*   Updated: 2026/08/11 15:26:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

unsigned int random_num(unsigned int range)
{
    unsigned int    x;
    unsigned int    r;

    while (42)
    {
        if (x = rand(), r = x % range, x - r <= -range)
            return (r);
    }
}

void    constructionchecks()
{
    Span    def;
    Span    def2(def);
    Span    spn(42);

    try
    {
        def.addNumber(42);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        def2.addNumber(42);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    spn.addNumber(42);
    spn.addNumber(0);
    def2 = spn;
    std::cout << spn.longestSpan() << "\n";
    std::cout << def2.longestSpan() << "\n";
    std::cout << spn.shortestSpan() << "\n";
    std::cout << def2.shortestSpan() << "\n";
}

void    functionalityTests()
{
    Span    empty(0);
    Span    one(1);
    Span    three(3);
    Span    negative(3);
    Span    dup(5);

    try
    {
        empty.addNumber(1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        empty.shortestSpan();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << "\n";
    }
    try
    {
        empty.longestSpan();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    one.addNumber(1);
    try
    {
        one.longestSpan();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        one.shortestSpan();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    three.addNumber(1);
    three.addNumber(42);
    std::cout << three.shortestSpan() << "\n";
    std::cout << three.longestSpan() << "\n";
    three.addNumber(41);
    std::cout << three.shortestSpan() << "\n";
    std::cout << three.longestSpan() << "\n";
    negative.addNumber(-1);
    negative.addNumber(-42);
    negative.addNumber(-41);
    std::cout << negative.shortestSpan() << "\n";
    std::cout << negative.longestSpan() << "\n";
    dup.addNumber(42);
    dup.addNumber(42);
    dup.addNumber(42);
    std::cout << dup.shortestSpan() << "\n";
    std::cout << dup.longestSpan() << "\n";
    dup.addNumber(43);
    dup.addNumber(43);
    std::cout << dup.shortestSpan() << "\n";
    std::cout << dup.longestSpan() << "\n";
}

void    stressTests()
{
    Span                large(20000);
    std::vector<int>    largevec;

    srand(time(NULL));
    for (int x = 0; x < 20000; x++)
        largevec.push_back(rand());
    large.addNumber(largevec.begin(), largevec.end());
    std::cout << large.shortestSpan() << "\n";
    std::cout << large.shortestSpan() << "\n";
}

int main()
{
    
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    constructionchecks();
    functionalityTests();
    stressTests();
    return 0;
}
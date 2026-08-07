/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 18:34:41 by marvin            #+#    #+#             */
/*   Updated: 2026/08/06 17:53:56 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

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

Base    *generate(void)
{
    unsigned int random = random_num(3);
    if (random == 0)
        return (new A);
    if (random == 1)
        return (new B);
    if (random == 2)
        return (new C);
    std::cout << "Random Number Process failed\n";
    return (NULL);
}

void    identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Class A\n";
    if (dynamic_cast<B*>(p))
        std::cout << "Class B\n";
    if (dynamic_cast<C*>(p))
        std::cout << "Class C\n";
    return ;
}

void    identify(Base &p)
{

    try
    {
        A &ptr = dynamic_cast<A&>(p);
        (void)ptr;
        std::cout << "Class A\n";
    }
    catch(const std::exception& e)
    {}
    try
    {
        B &ptr = dynamic_cast<B&>(p);
        (void)ptr;
        std::cout << "Class B\n";
    }
    catch(const std::exception& e)
    {}
    try
    {
        C &ptr = dynamic_cast<C&>(p);
        (void)ptr;
        std::cout << "Class C\n";
    }
    catch(const std::exception& e)
    {}
}

int main()
{
    srand(time(NULL));
    Base    *p = generate();
    
    if (p == NULL)
        return (1);
    identify(p);
    identify(*p);
    delete (p);
    for (int x = 0; x < 10; x++)
    {
        p = generate();
        if (p == NULL)
            return (1);
        identify(p);
        identify(*p);
        delete (p);
    }
    return (0);
}

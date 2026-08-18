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

#include "MutantStack.hpp"

void    list()
{
std::list<int> mstack;
mstack.push_back(5);
mstack.push_back(17);
std::cout << *(--(mstack.end())) << std::endl;
mstack.remove(17);
std::cout << mstack.size() << std::endl;
mstack.push_back(3);
mstack.push_back(5);
mstack.push_back(737);
//[...]
mstack.push_back(0);
std::list<int>::iterator it = mstack.begin();
std::list<int>::iterator ite = mstack.end();
++it;
--it;
while (it != ite)
{
std::cout << *it << std::endl;
++it;
}
std::list<int> s(mstack);
}

void    testConstructors()
{
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);

    MutantStack<int> cpy(mstack);
    MutantStack<int>::iterator it = cpy.begin();
    std::cout << *it << "\n";
    it++;
    std::cout << *it << "\n";
}

int main()
{
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);
std::cout << mstack.top() << std::endl;
mstack.pop();
std::cout << mstack.size() << std::endl;
mstack.push(3);
mstack.push(5);
mstack.push(737);
//[...]
mstack.push(0);
MutantStack<int>::iterator it = mstack.begin();
MutantStack<int>::iterator ite = mstack.end();
++it;
--it;
while (it != ite)
{
std::cout << *it << std::endl;
++it;
}
std::stack<int> s(mstack);
std::cout << "\n\n\n";
list();
testConstructors();
return 0;
}
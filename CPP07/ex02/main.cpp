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

#include "Array.hpp"


void    emptyArrays()
{
    Array<int>              iempty;
    Array<int>              icpy(iempty);
    Array<int>              iarg(0);
    Array<char>             cempty;
    Array<char>             ccpy(cempty);
    Array<char>             carg(0);

    Array<std::string>      sempty;
    Array<std::string>      scpy(sempty);
    Array<std::string>      sarg(0);

    std::cout << "Testing Empty Arrays with all constructors, first three, int Arrays:\n";
    std::cout << iempty.size() << "\n";
    std::cout << icpy.size() << "\n";
    std::cout << iarg.size() << "\n";
    std::cout << "Testing with char Arrays:\n";
    std::cout << cempty.size() << "\n";
    std::cout << ccpy.size() << "\n";
    std::cout << carg.size() << "\n";

    std::cout << "Testing with string Arrays:\n";
    std::cout << sempty.size() << "\n";
    std::cout << scpy.size() << "\n";
    std::cout << sarg.size() << "\n";
    std::cout << "Empty Array test complete\n\n";

}

void    Arraycopies()
{
    Array<int>              iArr1(5);
    Array<int>              iArr2(5);
    Array<char>             cArr1(5);
    Array<char>             cArr2(5);
    Array<std::string>      sArr1(5);
    Array<std::string>      sArr2(5);

    std::cout << "Copy Assignment Operator behaviour checks, alterations to the copy may not change the original, starting with Int arrays:\n";
    for (int x = 0; x < 5; x++)
        iArr1[x] = x;
    std::cout << "iArr1: \n";
    for (int x = 0; x < 5; x++)
        std::cout << iArr1[x];
    std::cout << "\n";
    iArr2 = iArr1;
    iArr2[2] = 42;
    std::cout << "iArr2 after copying and alteration:\n";
    for (int x = 0; x < 5; x++)
        std::cout << iArr2[x];
    std::cout << "\n";
    std::cout << "Checking if iArr1 remains unchanged:\n";
    for (int x = 0; x < 5; x++)
        std::cout << iArr1[x];
    std::cout << "\n";

    std::cout << "\nChar Arrays:\n";
    for (int x = 0; x < 5; x++)
        cArr1[x] = (char)(x + 48);
    std::cout << "cArr1:\n";
    for (int x = 0; x < 5; x++)
        std::cout << cArr1[x];
    std::cout << "\n";
    cArr2 = cArr1;
    cArr2[2] = 'c';
    std::cout << "cArr2 after copying and alteration:\n";
    for (int x = 0; x < 5; x++)
        std::cout << cArr2[x];
    std::cout << "\n";
    std::cout << "Checking if cArr1 remains unchanged:\n";
    for (int x = 0; x < 5; x++)
        std::cout << cArr1[x];
    std::cout << "\n";

    std::cout << "\nString Arrays:\n";
    sArr1[0] = "Hello";
    sArr1[1] = "my";
    sArr1[2] = "beautifull";
    sArr1[3] = "World";
    sArr1[4] = "!";
    std::cout << "sArr1:\n";
    for (int x = 0; x < 5; x++)
        std::cout << sArr1[x] << " ";
    std::cout << "\n";
    sArr2 = sArr1;
    sArr2[2] = "teribble";
    std::cout << "sArr2 after copying and alteration:\n";
    for (int x = 0; x < 5; x++)
        std::cout << sArr2[x] << " ";
    std::cout << "\n";
    std::cout << "Checking if sArr1 remains unchanged:\n";
    for (int x = 0; x < 5; x++)
        std::cout << sArr1[x] << " ";
    std::cout << "\n";

    std::cout << "\nDoing the same checks with the Copy Constructor:\n";
    Array<int>              iArr3(iArr1);
    Array<char>             cArr3(cArr1);
    Array<std::string>      sArr3(sArr1);

    iArr3[2] = 4242;
    cArr3[2] = 'C';
    sArr3[2] = "horrible";

    std::cout << "iArr3 after copying and alteration:\n";
    for (int x = 0; x < 5; x++)
        std::cout << iArr3[x];
    std::cout << "\n";
    std::cout << "Checking if iArr1 remains unchanged:\n";
    for (int x = 0; x < 5; x++)
        std::cout << iArr1[x];
    std::cout << "\n";

    std::cout << "cArr3 after copying and alteration:\n";
    for (int x = 0; x < 5; x++)
        std::cout << cArr3[x];
    std::cout << "\n";
    std::cout << "Checking if cArr1 remains unchanged:\n";
    for (int x = 0; x < 5; x++)
        std::cout << cArr1[x];
    std::cout << "\n";

    std::cout << "sArr3 after copying and alteration:\n";
    for (int x = 0; x < 5; x++)
        std::cout << sArr3[x] << " ";
    std::cout << "\n";
    std::cout << "Checking if sArr1 remains unchanged:\n";
    for (int x = 0; x < 5; x++)
        std::cout << sArr1[x] << " ";
    std::cout << "\n";
}

void    Arrayexceptions()
{
    Array<int>  arr(2);

    try
    {
        arr[3];
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
}

int main()
{
    emptyArrays();
    Arraycopies();
    Arrayexceptions();
}
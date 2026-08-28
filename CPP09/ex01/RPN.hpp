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

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <stack>
# include <list>
# include <iostream>
# include <algorithm>
# include <climits>
# include <fstream>
# include <sstream>

class RPN 
{
    private:
    std::stack<int, std::list<int>>     numbers;

        RPN();
        RPN (RPN &cpy);
        RPN& operator = (const RPN &cpy);
        
    public:
        RPN(std::stack<int, std::list<int>>);
        ~RPN();
    void                                execute(std::stack<int, std::list<int>> &numbers);
};

#endif
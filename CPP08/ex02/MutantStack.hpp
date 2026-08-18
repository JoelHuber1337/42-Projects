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

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <stack>
# include <iostream>
# include <list>

template <typename T>
class   MutantStack : public std::stack<T>
{
    public:
                                MutantStack();
                                MutantStack(const MutantStack &cpy);
                                ~MutantStack();
    MutantStack                 &operator = (const MutantStack &cpy);
	typedef typename std::stack<T>::container_type::iterator iterator;
    iterator                    begin();
    iterator                    end();
};

# include "MutantStack.tpp"

#endif
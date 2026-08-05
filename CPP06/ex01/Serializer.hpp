/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 16:10:23 by marvin            #+#    #+#             */
/*   Updated: 2026/08/04 16:10:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
# include "Data.hpp"
# include <iostream>
# include <string>
# include <stdint.h>

class   Serializer
{
    private:
                        Serializer();
                        Serializer(Serializer const &cpy);
                        ~Serializer();
                        Serializer &operator=(Serializer const &cpy);
    public:
    static              uintptr_t serialize(Data* ptr);
    static              Data* deserialize(uintptr_t raw);
};

#endif
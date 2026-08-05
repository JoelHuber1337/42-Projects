/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 16:10:49 by marvin            #+#    #+#             */
/*   Updated: 2026/08/04 16:10:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){}

Serializer::Serializer(Serializer const &cpy)
{
    *this = cpy;
}

Serializer::~Serializer(){}

Serializer& Serializer::operator=(Serializer const &cpy)
{
	if (this == &cpy)
		return (*this);
	return (*this);
}

uintptr_t   Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data*   Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}
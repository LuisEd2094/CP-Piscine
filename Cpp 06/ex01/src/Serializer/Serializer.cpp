/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 10:54:30 by lsoto-do          #+#    #+#             */
/*   Updated: 2024/01/01 10:54:31 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp" 

Serializer::Serializer(void) {}
Serializer::Serializer(const Serializer& src) {(void)src;}
Serializer& Serializer::operator=(const Serializer& rhs) {
    (void)rhs;
    return (*this);
}

Serializer::~Serializer() {}


uintptr_t Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));

}

Data* Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast <Data* >(raw));
}

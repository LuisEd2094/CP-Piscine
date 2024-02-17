/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 10:54:12 by lsoto-do          #+#    #+#             */
/*   Updated: 2024/01/01 10:54:14 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include "Data.hpp"

#ifdef _WIN32
    typedef unsigned __int32 uintptr_t; // Assuming 32-bit Windows
#else
    typedef unsigned long uintptr_t; // Assuming 32-bit Unix-like system
#endif


class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer & other);
        Serializer& operator=(const Serializer& rhs);
    public:
        ~Serializer();
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif

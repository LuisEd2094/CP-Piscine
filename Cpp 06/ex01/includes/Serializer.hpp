#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include "Data.hpp"
# include <cstdint>


class Serializer
{
    public:
        Serializer();
        ~Serializer();
        Serializer(const Serializer & other);
        Serializer& operator=(const Serializer& rhs);

        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif
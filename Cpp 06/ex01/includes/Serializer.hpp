#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include "Data.hpp"
# include <cstdint>


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

#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"
#include <cstdint>


int main()
{
    Data data;


    std::cout << data.m_age << " " << data.m_name << " " << Data::m_data_total << std::endl;
    std::cout << "data address :" <<  &data << std::endl;

    uintptr_t ptr = Serializer::serialize(&data);

    std::cout << &ptr << std::endl;

    Data * data_d = Serializer::deserialize(ptr);

    std::cout << data_d->m_age << " " << data_d->m_name << " " << Data::m_data_total << std::endl;
    std::cout << "data_d dereference address :" << &*data_d << std::endl;

    std::cout << " are they equal? = " << (&*data_d == &data) << std::endl;
}

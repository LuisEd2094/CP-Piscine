#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"
#include <cstdint>


int main()
{
    Data data;


    std::cout << data.m_age << " " << data.m_name << " " << data.m_data_total << std::endl;
    std::cout << &data << std::endl;

    uintptr_t ptr = Serializer::serialize(&data);

    std::cout << &ptr << std::endl;

    Data * data_d = Serializer::deserialize(ptr);

    std::cout << data_d->m_age << " " << data_d->m_name << " " << data_d->m_data_total << std::endl;
    std::cout << &data_d << std::endl;
}
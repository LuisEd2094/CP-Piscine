#include "Data.hpp" 

int Data::m_data_total = 0;

Data::Data(void) : 
    m_name("Default"),
    m_age(0)
{
    m_data_total += 1
}
Data::Data(const Data& src) :
    m_name(src.m_name),
    m_age(src.m_age)
    {
        m_data_total += 1;
    }
Data& Data::operator=(const Data& rhs) {
    if (this != &rhs)
    {
        this->m_name = rhs.m_name;
        this->m_age = rhs.m_age;
    }
    return (*this);
}

Data::~Data() {
    m_data_total -= 1;
}

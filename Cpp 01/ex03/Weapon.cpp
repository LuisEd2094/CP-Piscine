#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
    m_type = type;
}

Weapon::~Weapon(void)
{
}

void Weapon::setType(std::string type)
{
    m_type = type;
}

const std::string& Weapon::getType(void)
{
    return m_type;
}
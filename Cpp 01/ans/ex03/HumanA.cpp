#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : m_name(name), m_weapon(weapon)
{
}

HumanA::~HumanA(void)
{
    
}

void HumanA::attack(void)
{
    std::cout << this->m_name << " attacks with their " << this->m_weapon.getType() << std::endl;
}
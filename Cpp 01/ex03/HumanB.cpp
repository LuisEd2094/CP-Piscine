#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->m_name = name; 
    this->m_weapon = NULL;
}

HumanB::~HumanB(void)
{
    
}

void HumanB::setWeapon(Weapon  &weapon)
{
    this->m_weapon = &weapon;
}


void HumanB::attack(void)
{
    std::cout << this->m_name << " attacks with their ";
    if (this->m_weapon)
        std::cout << this->m_weapon->getType();
    else
        std::cout << "fists";
    std::cout << std::endl;
}

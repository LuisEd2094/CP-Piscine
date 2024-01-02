#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    _name = name; 
    _weapon = NULL;
}

HumanB::~HumanB(void)
{
    
}

void HumanB::setWeapon(Weapon  &weapon)
{
    _weapon = &weapon;
}


void HumanB::attack(void)
{
    std::cout << _name << " attacks with their ";
    if (_weapon)
        std::cout << _weapon->getType();
    else
        std::cout << "fists";
    std::cout << std::endl;
}

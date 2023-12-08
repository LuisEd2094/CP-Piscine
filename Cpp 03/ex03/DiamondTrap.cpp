#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
    : ClapTrap("default_clap_name"), FragTrap("default"), ScavTrap("default"), m_name("default")
{
    std::cout << "Default DiamondTrap constructor called" << std::endl;
    this->FragTrap::m_hp = 100;
    this->ScavTrap::m_energy = 50;
    this->FragTrap::m_dmg = 30;
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name) , FragTrap(name) , ScavTrap(name)
{
	std::cout << "DiamondTrap(name) constructor called, created DiamondTrap" << this->m_name << std::endl;
    this->m_name = name;
    this->ClapTrap::m_name = name + "_clap_name";
    this->FragTrap::m_hp = 100;
    this->ScavTrap::m_energy = 50;
    this->FragTrap::m_dmg = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& toCocpy)
    : ClapTrap(toCocpy) , FragTrap(toCocpy) , ScavTrap(toCocpy)
{
    std::cout << "DiamondTrap copy constructor called for " << this->m_name << std::endl; 
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& DiamondTrap)
{
    std::cout << "DiamondTrap operator = called for " << this->m_name << std::endl;
    if (this != &DiamondTrap)
    {
        ClapTrap::operator=(DiamondTrap);
        ScavTrap::operator=(DiamondTrap);
        FragTrap::operator=(DiamondTrap);
        std::cout << "Operator = done" << std::endl;
    }
    return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap deconstructor called for " << this->m_name << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap " << this->m_name;
    if (!ClapTrap::canTakeAction())
        std::cout << "He can't guard the gates!" << std::endl;
    else
    {
        this->m_energy -= 1;
	    std::cout << "whoAmI(): I am DiamondTrap " << this->m_name << " and my ClapTrap name is " << this->ClapTrap::m_name << std::endl;
    }
}
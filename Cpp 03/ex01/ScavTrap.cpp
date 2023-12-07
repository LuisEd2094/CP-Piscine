#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
    : ClapTrap()
{
    std::cout << "Default ScavTrap constructor called" << std::endl;
    this->m_hp = 100;
    this->m_energy = 50;
    this->m_dmg = 20;
}

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name)
{
	std::cout << "ScavTrap(name) constructor called, created ScavTrap" << this->m_name << std::endl;
    this->m_hp = 100;
    this->m_energy = 50;
    this->m_dmg = 20;
}

ScavTrap::ScavTrap(const ScavTrap& toCocpy)
    : ClapTrap(toCocpy)
{
    std::cout << "ScavTrap copy constructor called for " << this->m_name << std::endl; 
}

ScavTrap& ScavTrap::operator=(const ScavTrap& scavtrap)
{
    ClapTrap::operator=(scavtrap);

    std::cout << "ScavTrap operator = called for " << this->m_name << std::endl;
    return (*this);
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap deconstructor called for " << this->m_name << std::endl;
}


void ScavTrap::attack(std::string const& target)
{
    std::cout << "ScavTrap " << this->m_name;
    if (!ClapTrap::canTakeAction())
        std::cout << "He can't attack!" << std::endl;
    else
    {
        this->m_energy -= 1;
        std::cout << " attacks " << target << ", causing " << this->m_dmg << " points of damage!" << std::endl;

    }
}
void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->m_name << " has entered Gate keeper mode!" << std::endl;
}
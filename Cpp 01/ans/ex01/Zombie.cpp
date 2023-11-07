#include "Zombie.hpp"

Zombie::~Zombie(void)
{
    std::cout << m_name << " was destroyed" << std::endl;
}

void    Zombie::announce(void)
{
    std::cout << m_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::setName(std::string name)
{
    this->m_name = name;
    return ;
}
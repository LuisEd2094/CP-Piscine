#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    m_name = name;
}

Zombie::~Zombie(void)
{
    std::cout << m_name << " was destroyed" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << m_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
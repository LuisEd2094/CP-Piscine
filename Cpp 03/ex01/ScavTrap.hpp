#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap(void);
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& toCocpy);

        ScavTrap& operator=(const ScavTrap& scavtrap);

        ~ScavTrap();

        void attack(std::string const& target);
        void guardGate();
};
#endif
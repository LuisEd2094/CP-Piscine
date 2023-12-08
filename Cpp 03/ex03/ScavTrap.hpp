#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class ScavTrap : virtual public ClapTrap
{
    public:
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& toCocpy);

        ScavTrap& operator=(const ScavTrap& scavtrap);

        ~ScavTrap();

        void attack(std::string const& target);
        void guardGate();
    private:
        ScavTrap();
};
#endif
#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include <iostream>

class DiamondTrap : public FragTrap, public ScavTrap
{
    public:
        DiamondTrap(void);
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap& toCocpy);

        DiamondTrap& operator=(const DiamondTrap& DiamondTrap);

        ~DiamondTrap();

        using   ScavTrap::attack;
	    void    whoAmI();

    private:
        std::string m_name;
};
#endif
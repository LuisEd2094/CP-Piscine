#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class FragTrap : public ClapTrap
{
    public:
        FragTrap(void);
        FragTrap(std::string name);
        FragTrap(const FragTrap& toCocpy);

        FragTrap& operator=(const FragTrap& FragTrap);

        ~FragTrap();

        void attack(std::string const& target);
        void highFivesGuys(void);
};
#endif
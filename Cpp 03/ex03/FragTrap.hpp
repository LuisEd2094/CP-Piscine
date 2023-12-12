#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class FragTrap :virtual public ClapTrap
{
    public:
        FragTrap(std::string name);
        FragTrap(const FragTrap& toCocpy);

        FragTrap& operator=(const FragTrap& FragTrap);

        ~FragTrap();

        void attack(std::string const& target);
        void highFivesGuys(void);
    private:
        FragTrap();
};
#endif
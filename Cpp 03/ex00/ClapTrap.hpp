#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>


class ClapTrap
{
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& toCopy);
        ClapTrap& operator=(const ClapTrap& toCopy);

        ~ClapTrap();

        bool    canTakeAction();
        void    attack(std::string const& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
    
    private:
        std::string     m_name;
        unsigned int    m_hp;
        unsigned int    m_energy;
        unsigned int    m_dmg;
};

#endif
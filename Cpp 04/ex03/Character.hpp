#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"


class Character : public ICharacter
{
    public:
        Character(void);
        Character(const std::string& name);
	    Character(const Character& other);
	
    	Character& operator=(const Character& rhs);
	    ~Character(void);

        std::string const & getName(void) const;
	    void equip(AMateria* m);
	    void unequip(int idx);
	    void use(int idx, ICharacter& target);
    private:
        AMateria*   m_inventory[4];
        std::string m_name;
};

#endif
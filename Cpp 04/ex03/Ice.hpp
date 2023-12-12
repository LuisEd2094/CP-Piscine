#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include <iostream>

class Ice : public AMateria
{
    public:
        Ice(void);
        Ice(const Ice& other);
        Ice& operator=(const Ice& rhs);
        ~Ice(void);

        void use(ICharacter& target);
	    AMateria* clone(void) const;
    protected:
        static std::string m_type;
};

#endif
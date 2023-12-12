#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
    protected:
        std::string m_type;

    public:
        AMateria(void);
        AMateria(std::string const& type);
        AMateria(const AMateria& src);
        AMateria& operator=(const AMateria& rhs);
        std::string const& getType(void) const;

        virtual AMateria* clone(void) const = 0;
        virtual ~AMateria(void) = 0;
        virtual void use(ICharacter& target) = 0;
};

#endif
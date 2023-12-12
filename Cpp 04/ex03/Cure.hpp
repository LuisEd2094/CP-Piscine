#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include <iostream>

class Cure : public AMateria
{
    public:
        Cure(void);
        Cure(std::string  const& type);
        Cure(const Cure& other);
        Cure& operator=(const Cure& rhs);
        ~Cure(void);

        void use(ICharacter& target);
	    AMateria* clone(void) const;

};


#endif
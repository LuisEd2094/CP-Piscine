#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "IMateriaSource.hpp"
class AMateria;

class MateriaSource : public IMateriaSource
{
    public:
        MateriaSource(void);
	    MateriaSource(const MateriaSource& other);
	
    	MateriaSource& operator=(const MateriaSource& rhs);
	    ~MateriaSource(void);

        void learnMateria(AMateria* m);
	    AMateria* createMateria(const std::string& type);

    private:
        AMateria*   m_materia[4];
};

#endif
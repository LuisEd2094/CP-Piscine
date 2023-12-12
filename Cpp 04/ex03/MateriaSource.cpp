#include "MateriaSource.hpp"
#include "AMateria.hpp"


MateriaSource::MateriaSource(void) 
{
	for (int i = 0; i < 4; i++)
		this->m_materia[i] = NULL;
}
MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < 4; i++)
		MateriaSource::learnMateria(other.m_materia[i]);
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs)
{
    if (this != &rhs)
    {
        for (int i = 0; i < 4; i++)
		    MateriaSource::learnMateria(rhs.m_materia[i]);
    }
    return *this;
}

MateriaSource::~MateriaSource(void)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->m_materia[i])
            delete this->m_materia[i];
    }
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (m)
    {
        for (int i = 0; i < 4; i++)
        {
            if (!this->m_materia[i])
            {
                this->m_materia[i] = m;
                break;
            }
        }
    }
}
AMateria* MateriaSource::createMateria(const std::string& type)
{
    if (!type.empty())
    {
        for (int i = 0; i < 4; i++)
        {
            if (this->m_materia[i]->getType() == type)
                return (this->m_materia[i]->clone());
        }
    }
    return (0);
}
#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
class AMateria
{
    protected:
        std::string m_type;

    public:
        AMateria(void);
        AMateria(std::string const& type);
        AMateria(const AMateria& src);
        AMateria& operator=(const AMateria& rhs);
        virtual ~AMateria(void) = 0;

        std::string const& getType(void) const;
        virtual AMateria* clone(void) const = 0;



};

#endif
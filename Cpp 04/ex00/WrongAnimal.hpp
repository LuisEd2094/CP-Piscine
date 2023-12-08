#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
    std::string m_type;

public:
    WrongAnimal(void);
    WrongAnimal(std::string type);
    virtual ~WrongAnimal(void);

    WrongAnimal(const WrongAnimal& src);
    WrongAnimal& operator=(const WrongAnimal& rhs);

    virtual void    makeSound(void) const;
    std::string     getType(void) const; 
};

#endif
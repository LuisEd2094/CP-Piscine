#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
    protected:
        std::string m_type;
        Animal(void);
        Animal(std::string type);

        Animal(const Animal& src);
        Animal& operator=(const Animal& rhs);


    public:
        virtual ~Animal(void);

        virtual void    makeSound(void) const;
        std::string     getType(void) const; 
};

#endif
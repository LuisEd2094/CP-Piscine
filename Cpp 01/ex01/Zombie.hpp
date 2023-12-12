#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cerrno>

class Zombie 
{
    private:
        std::string m_name;
    public:
        Zombie() : m_name("") {};
        ~Zombie(void);

        void    announce(void);
        void    setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);
#endif
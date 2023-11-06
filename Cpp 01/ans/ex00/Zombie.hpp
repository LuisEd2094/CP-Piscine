#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie 
{
    private:
        std::string m_name;
    public:
        Zombie(std::string name);
        ~Zombie(void);

        void announce(void);
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );
#endif
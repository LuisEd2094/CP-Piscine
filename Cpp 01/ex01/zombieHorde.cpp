#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    try 
    {
        std::string tempName;

        Zombie *horde = new Zombie[N];
        for (int i = 0; i < N; i++)
            horde[i].setName(name);
        return (horde);
    }
    catch (const std::bad_alloc& e)
    {
        std::perror("Error");
        return (NULL);
    }
}
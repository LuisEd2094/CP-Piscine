#include "Zombie.hpp"

int main(void)
{
    Zombie* zombie1;
    Zombie  zombie2("Zombie 2");;


    zombie1 = newZombie("Zombie 1");
    zombie1->announce();
    delete zombie1;


    zombie2.announce();

    randomChump("Random");
    return (0);
}
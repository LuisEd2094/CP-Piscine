#include "Zombie.hpp"

int main(void)
{
    Zombie* zombie1;

    zombie1 = new Zombie();
    zombie1->announce();
    return 1;
}
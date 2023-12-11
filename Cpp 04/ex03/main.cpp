#include "Ice.hpp"
#include "AMateria.hpp"

int main(void)
{
    Ice* newIce = new Ice();
    Ice* newIce2 = new Ice("ice2");

    std::cout << newIce->getType() << newIce << std::endl;
    std::cout << newIce2->getType() << newIce2 << std::endl;

    Ice original("Og");
    Ice ice3 = original;

    std::cout << original.getType() << &original << std::endl;

    std::cout << ice3.getType() << &ice3 << std::endl;

    Ice ice4(original);
    std::cout << ice4.getType() << &ice4 << std::endl;

    Ice *ice5 = newIce->clone();

    std::cout << ice5->getType() << &ice5 << std::endl;
    std::cout << newIce->getType() << &newIce << std::endl;


    delete newIce;
    delete newIce2;
}
#include <vector>
#include <list>
#include <iostream>


void solveWithList(int argc, std::string *strs)
{
    std::cout << argc << std::endl;

    for(std::string::iterator it = strs->begin(); it != strs->end(); ++it )
    {
        std::cout << *it << std::endl;
    }
}

void solveWithVector(int argc, std::string *strs)
{
    std::cout << argc << std::endl;

    for(std::string::iterator it = strs->begin(); it != strs->end(); ++it )
    {
        std::cout << *it << std::endl;
    }
}

std::string* checkArgs(int argc, char *argv[])
{
    std::string* strs = new std::string[argc];

    for (int i = 0; i <= argc; ++i)
        strs[i] = static_cast<std::string>(argv[i]);
    return (strs);
}


int main(int argc, char *argv[])
{
    std::string* strs =  checkArgs(argc - 1, &argv[1]);
    solveWithVector(argc - 1, strs);
    solveWithList(argc - 1, strs);

    delete strs;

}


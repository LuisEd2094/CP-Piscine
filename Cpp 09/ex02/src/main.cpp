#include <vector>
#include <deque>
#include <iostream>
#include <PmergeMe.tpp>
int* checkArgs(int argc, char *argv[])
{
    try
    {
        int* container = new int[argc + 1];

        for (int i = 0; i < argc; ++i)
            container[i] = std::atoi(argv[i]);
        return (container);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        std::exit(EXIT_FAILURE);
    }
}


int main(int argc, char *argv[])
{
    int* ints =  checkArgs(argc - 1, &argv[1]);

    solve<std::vector<int> > (argc - 1, ints);
    solve<std::deque<int> > (argc - 1, ints);

    delete [] ints;
}


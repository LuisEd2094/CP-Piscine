
#include <iostream>
#include <PmergeMe.hpp>

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
    clock_t start, end;
    double time;

/*     start = clock();
    solveMergeSort<std::vector<int> > (argc - 1, ints);
    end = clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;

    std::cout << "Vector time: " << time << std::endl;

    start = clock();
    solveMergeSort<std::deque<int> > (argc - 1, ints);
    end = clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;

    std::cout << "Deque time: " << time << std::endl; */

/*      start = clock();

    std::vector<int> vect (argc - 1);
    for (int i = 0; i < argc - 1; ++i)
        vect[i] = ints[i];
    // for (int i = 0; i < argc - 1; ++i)
    //     std::cout << vect[i]  << std::endl;
    solverMergeInsertVectorIncorrect(vect);
    end = clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;

    std::cout << "MergeInsertVector INCORRECT time: " << time << std::endl; */

    start = clock();
    solveMergeInsert<int, std::vector>(argc - 1, ints);

    end = clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;

    
    std::cout << "MergeInsertVector  CORRECT time: " << time << std::endl;

     start = clock();
    solveMergeInsert<int, std::deque>(argc - 1, ints);

    end = clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;

    
    std::cout << "MergeInsertDeque CORRECT time: " << time << std::endl; 
    delete [] ints;
}


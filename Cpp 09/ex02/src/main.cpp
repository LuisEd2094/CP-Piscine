
#include <iostream>
#include <PmergeMe.hpp>

int* checkArgs(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Not enough arguments. Provide me with a range of numbers to order" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    int* ints;
    bool isOrdered = 1;
    try
    {
        ints = new int[argc + 1];
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        std::exit(EXIT_FAILURE);
    }
    for (int i = 0; i < argc; ++i)
    {
        for (int j = 0; argv[i][j]; ++j)
        {
            if (!isdigit(argv[i][j]))
            {
                std::cerr << "Invalid argument: " << argv[i] << std::endl;
                delete [] ints;
                std::exit(EXIT_FAILURE);
            }
        }
        ints[i] = std::atoi(argv[i]);
    }
    for (int i = 0; i < argc - 1 && isOrdered; ++i)
    {
        if (ints[i] > ints[i + 1])
            isOrdered = 0;
    }
    if (isOrdered)
    {
        std::cerr << "This is ordered! Give me something to order!" << std::endl;
        delete [] ints;
        std::exit(EXIT_FAILURE);
    }
    return (ints);
}

void failedAttempts(int argc, int *ints)
{
    clock_t start, end;
    double time;

    start = clock();
    solveMergeSort<std::vector<int> > (argc - 1, ints);
    end = clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
    std::cout << "MergeVector time: " << time << std::endl;
    start = clock();
    solveMergeSort<std::deque<int> > (argc - 1, ints);
    end = clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
    std::cout << "MergeDeque time: " << time << std::endl;
    start = clock();
    std::vector<int> vect (argc - 1);
    for (int i = 0; i < argc - 1; ++i)
        vect[i] = ints[i];
    solverMergeInsertVectorIncorrect(vect);
    end = clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;

    std::cout << "MergeInsertVector INCORRECT time: " << time << std::endl; 
}

int main(int argc, char *argv[])
{
    int* ints =  checkArgs(argc - 1, &argv[1]);
    int i;
    clock_t start, end;
    double time;


    std::cout << "Before: ";
    for(i = 1 ; i < 21 && i < argc; ++i)
        std::cout << argv[i] << " ";
    if (i >= 21)
        std::cout << "\nToo many arguments, didn't print everything";
    std::cout << std::endl;
    /*Solve merge works with any ints that has access to push_back, insert, pop_back, back, size and iterators (begind end)
    such as vectors and deques*/
    start = clock();
    end = solveMergeInsert<int, std::vector>(argc - 1, ints);
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
    std::cout << "MergeInsertVector time to process " << argc - 1 << " elemets : " << time << std::endl; 
    start = clock();
    end = solveMergeInsert<int, std::deque>(argc - 1, ints);
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
    std::cout << "MergeInsertDeque time to process " << argc - 1 << " elemets : " << time << std::endl; 
    /*this calls merge sort and merge Binary, but they are the wrong implementation
    leaveing it here in case we want to check how they perform. They are much faster, but they perform more checks*/
    //failedAttempts(argc, ints);
    delete [] ints;
}


#include <vector>
#include <list>
#include <iostream>



void merge(std::string *strs, const int left, const int mid, const int right)
{
    const int subArrayOne = mid - left  + 1;
    const int subArrayTwo = right - mid;
    std::string* leftArray = NULL;
    std::string* rightArray = NULL;
    try
    {
        leftArray = new std::string[subArrayOne];
        rightArray = new std::string[subArrayTwo];
    }
    catch (const std::bad_alloc& e)
    {
        std::cerr << e.what() << std::endl;
        std::exit(EXIT_FAILURE);
    }
    for (int i = 0; i < subArrayOne; ++i)
        leftArray[i] = strs[left + i];
    for (int i = 0; i < subArrayTwo; ++i)
        rightArray[i] = strs[mid + 1 + i];


    int indxSubOne = 0, indxSubTwo = 0, indxMerge = left;

    while (indxSubOne < subArrayOne && indxSubTwo < subArrayTwo)
    {
        if (leftArray[indxSubOne] <= rightArray[indxSubTwo])
        {
            strs[indxMerge] = leftArray[indxSubOne];
            indxSubOne++;
        }
        else
        {
            strs[indxMerge] = rightArray[indxSubTwo];
            indxSubTwo++;
        }
        indxMerge++;

    }
    while (indxSubOne < subArrayOne)
    {
        strs[indxMerge] = leftArray[indxSubOne];
        indxSubOne++;
        indxMerge++;
    }

    while (indxSubTwo < subArrayTwo)
    {
        strs[indxMerge] = rightArray[indxSubTwo];
        indxSubTwo++;
        indxMerge++;
    }
    delete [] leftArray;
    delete [] rightArray;
}

void mergeSort(std::string *strs, const int begin, const int end)
{
    if (begin >= end)
        return;
    int mid = begin + (end - begin) / 2;
    mergeSort(strs, begin, mid);
    mergeSort(strs, mid + 1, end);
    merge(strs, begin, mid, end);

}

void solveWithList(std::size_t argc, std::string *strs)
{
    std::list<std::string> list(argc);


    /*can't init both the it and the i on the for loop*/
    int i;
    std::list<std::string>::iterator it;

    mergeSort(strs, 0, argc - 1);
    
    // for (it = list.begin(), i = 0; it != list.end(); ++it, ++i)
    //     *it = strs[i];
    // for (it = list.begin(); it != list.end(); ++it)
    //     std::cout << *it << std::endl;
}

void solveWithVector(std::size_t argc, std::string *strs)
{   

    std::vector<std::string> vector(argc);


    for (std::size_t i = 0; i < argc; ++i)
        vector[i] = strs[i];

    for (std::size_t i = 0; i < argc; ++i)
        std::cout << vector[i] << std::endl;
}

std::string* checkArgs(int argc, char *argv[])
{
    try
    {
        std::string* strs = new std::string[argc + 1];

        for (int i = 0; i < argc; ++i)
            strs[i] = static_cast<std::string>(argv[i]);
        return (strs);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        std::exit(EXIT_FAILURE);
    }
}


int main(int argc, char *argv[])
{
    std::string* strs =  checkArgs(argc - 1, &argv[1]);
    for (int i = 0; i < argc - 1; i++)
        std::cout << strs[i] << std::endl;
    //solveWithVector(static_cast<std::size_t>(argc - 1),  strs);
    solveWithList(static_cast<std::size_t>(argc - 1), strs);
    
    
    std::cout << "Finished with merge sort" << std::endl;

    for (int i = 0; i < argc - 1; ++i)
        std::cout << strs[i] << std::endl;
    delete []strs;
}


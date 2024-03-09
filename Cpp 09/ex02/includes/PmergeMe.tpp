#include <PmergeMe.hpp>
#define CONTAINER Container<T, std::allocator<T> > 
#define CONTAINER_CONTAINER Container< Container<T, std::allocator<T> >,  std::allocator<Container <T, std::allocator <T> > > >



template <typename T, template <typename, typename> class Container>
void generatePairs(int*& container, CONTAINER_CONTAINER &twoPairs, std::size_t& size, bool& isOdd, int& odd)
{
    int i, j;
    for (i = 0, j = 0; i < size; i += 2,  ++j)
    {
        CONTAINER temp;
        if (container[i] <  container[i + 1])
        {
            temp.push_back(container[i]);
            temp.push_back(container[i + 1]);
            twoPairs.push_back(temp);
        }
        else
        {
            temp.push_back(container[i + 1]);
            temp.push_back(container[i]);
            twoPairs.push_back(temp);
        }

    }
    if (isOdd)
    {
        odd = container[i];
    }
}
template <typename T, template <typename, typename> class Container>
void addFirstElemtTocontaineror(CONTAINER &container, CONTAINER_CONTAINER& twoPairs)
{
    int i = 0;


    for (typename CONTAINER_CONTAINER::iterator it = twoPairs.begin(); it != twoPairs.end(); ++it, ++i)
    {
        CONTAINER& innercontaineror = *it;
        container.push_back(*(innercontaineror.begin()));
    }
    // if ((--twoPairs.end())->size() > 1)
    //     container[i] = *(--((--twoPairs.end())->end()));
}

// int binarySearch(Container<int>&container, int value, int start, int end)
// {
//     if (start == end)
//     {
//         if (container[start] > value)
//             return (start);
//         else
//             return (start + 1);
//     }
//     else if (start > end)
//         return (start);
//     int midPoint = (start + end) / 2;

//     if (container[midPoint] < value)
//         return (binarySearch(container, value, midPoint + 1, end));
//     else if (container[midPoint] > value)
//         return (binarySearch(container, value, start, midPoint - 1));
//     else
//         return (midPoint);

// }

// // We have the first twoPairs.size() elemts sorted inside containeror. We need to keep track of this subcontaineror to know where to look for
// // the binary Inserton
// void binaryInsertion(Container<int>&container, Container<Container<int> >& twoPairs)
// {
//     std::size_t subcontainerSize = twoPairs.size();
//     for (int i = 0; i < twoPairs.size(); ++i)
//     {
//         if (twoPairs[i].size() > 1) //Protect the odd
//         {
//             int index = binarySearch(container, twoPairs[i][1], 0, subcontainerSize);
//             container.insert(container.begin() + index, twoPairs[i][1]);
//             subcontainerSize++;
//         }
//     }


// }

template <typename T, template <typename, typename> class Container>
int binarySearch(CONTAINER &vect, int value, int start, int end)
{
    if (start == end)
    {
        if (vect[start] > value)
            return (start);
        else
            return (start + 1);
    }
    else if (start > end)
        return (start);
    int midPoint = (start + end) / 2;

    if (vect[midPoint] < value)
        return (binarySearch(vect, value, midPoint + 1, end));
    else if (vect[midPoint] > value)
        return (binarySearch(vect, value, start, midPoint - 1));
    else
        return (midPoint);

}


// 1 0 3  11 10 9 8 7 6 21 20 19 18
// 1, 1, 3, 5, 11, 21
template <typename T, template <typename, typename> class Container>
void binaryInsertion(CONTAINER&container, CONTAINER_CONTAINER& twoPairs)
{
/*     int jacobsthal_diff[] =  {
        2, 2, 2, 6,

 }; */
    /*
    
        3 - 1 = 2. 
        last index 1.
        5 - 3 = 2
        index last index + 2 = 3
        11 - 5 = 6
        3 + 6 index = 9. 
    */
/*     int *jacobSequence;
    int jacobSize; */

    //getJacobSequence(jacobSequence, jacobSize);
    int jacobIndexs[] ={
        0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525,
    };
/*     int loopSize;
    for (loopSize = 0; jacobIndexs[loopSize + 1]; loopSize++){std::cout << "HOLA";}; */
    int containerIndex = 0;
    int lastIndex = 0;

    for (int i = 0; ; ++i)
    {
        if (jacobIndexs[i] >= twoPairs.size() - 1 )
            break;
        int moves = jacobIndexs[i + 1] - jacobIndexs[i];
/*         if (lastIndex + moves > twoPairs.size())
            moves = twoPairs.size() - lastIndex - 2; */
        for (int j = 0; j < moves; ++j)
        {
            int start = containerIndex;
            int end = container.size();
            int pairIndex = lastIndex - j;
            int value = twoPairs[pairIndex][1];
            int index = binarySearch(container, value, start, end);
            container.insert(container.begin() + index, value);
            containerIndex++;
        }

        lastIndex += moves; 
    }

}
#include<iostream>
#include<vector>
#include<algorithm>
#include <fstream>

template <typename T, template <typename, typename> class Container>
void solveMergeInsert(std::size_t argc, int *ints)
{
    if (argc < 2) return ;
    CONTAINER container;
    int         odd;
    bool        isOdd = argc % 2;
    std::size_t pairSize = isOdd ? argc - 1 : argc;

    
    //getJacob(argc);
    //Init twoPair list to have half or half + 1 argc if argc is odd. internal containerors are size 2 int
    CONTAINER_CONTAINER twoPairs;
    generatePairs(ints, twoPairs, pairSize, isOdd, odd);
    mergeSort(twoPairs, 0, twoPairs.size() - 1);
    addFirstElemtTocontaineror(container, twoPairs);
    container.push_back(*(--((--twoPairs.end())->end()))); // push second elem of the last elemt
    binaryInsertion(container, twoPairs);
    if (isOdd)
    {
        int index = binarySearch(container, odd, 0, container.size() - 1);
        if (index == container.size())
            container.push_back(odd);
        else
            container.insert(container.begin() + index, odd);

    }

     CONTAINER temp(argc);
    typename CONTAINER::iterator it;
    for (int i = 0; i < argc; ++i)
    {
        temp[i] = ints[i];
    }

    // Open a file for writing
    std::ofstream outputFile("temp.txt");
    
    // Redirect std::cout to the file
    std::streambuf *coutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(outputFile.rdbuf());
    
    // Write to std::cout (which now redirects to the file)
    
    // Restore std::cout
    
    // Close the file
    std::sort(temp.begin(), temp.end());
    for (int i = 0; i < argc; ++i)
    {   
        std::cout << temp[i] << "\n";
    }
    std::cout.rdbuf(coutBuffer);
    outputFile.close();

    std::ofstream outputFile2("my.txt");
    coutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(outputFile2.rdbuf());
    for (int i = 0; i < argc; ++i)
    {   
        std::cout << container[i] << "\n";
    }
    std::cout.rdbuf(coutBuffer);
    outputFile.close();


    std::cout << "SORTED!" << std::endl;
    // Container<Container<int> > twoPairs(size % 2 == 0 ? size / 2 : (size / 2) + 1, Container<int>(2));


    // addFirstElemtTocontaineror(container, twoPairs);
    // binaryInsertion(container, twoPairs);
    // container.resize(size);
    // for (Container<int>::iterator it = container.begin(); it != container.end(); ++it)
    //      std::cout <<  *it << std::endl;

}

// #include <PmergeMe.hpp>

// void generatePairs(std::containeror<int>& container, std::containeror<std::containeror<int> >& twoPairs, std::size_t& size, bool& isOdd, int& odd)
// {
//     for (int i = 0, j = 0; i < size; i += 2,  ++j)
//     {
//         if (container[i] <  container[i + 1])
//         {
//             twoPairs[j][0] = container[i];
//             twoPairs[j][1] = container[i + 1];
//         }
//         else
//         {
//             twoPairs[j][0] = container[i + 1];
//             twoPairs[j][1] = container[i];  
//         }

//     }
//     if (isOdd)
//     {
//         odd = container[container.size() - 1];
//         twoPairs[twoPairs.size() - 1].resize(1);

//     }
// }

// void addFirstElemtTocontaineror(std::containeror<int>&container, std::containeror<std::containeror<int> >& twoPairs)
// {
//     int i = 0;
//     for (std::containeror<std::containeror<int> >::iterator it = twoPairs.begin(); it != twoPairs.end(); ++it, ++i)
//     {
//         std::containeror<int>& innercontaineror = *it;
//         container[i] = *(innercontaineror.begin());
//     }
//     if ((--twoPairs.end())->size() > 1)
//         container[i] = *(--((--twoPairs.end())->end()));
// }

// int binarySearch(std::containeror<int>&container, int value, int start, int end)
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
// void binaryInsertion(std::containeror<int>&container, std::containeror<std::containeror<int> >& twoPairs)
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


// template <typename Container>
// void solverMergeInsertcontainerorCorrect(std::size_t argc, int *ints)
// {
//     Container container(argc);
    
//     for (int i = 0; i < argc; ++i)
//         container[i] = ints[i];

//     std::size_t size = container.size();
//     int         odd;
//     bool        isOdd = size % 2;

//     if (size < 2) return ;
//     //Init twoPair list to have half or half + 1 argc if argc is odd. internal containerors are size 2 int
//     std::containeror<std::containeror<int> > twoPairs(size % 2 == 0 ? size / 2 : (size / 2) - 1, std::containeror<int>(2));


//     generatePairs(container, twoPairs, size, isOdd, odd);    
//     mergeSort(twoPairs, 0, twoPairs.size() - 1);
//     addFirstElemtTocontaineror(container, twoPairs);
//     binaryInsertion(container, twoPairs);
//     container.resize(size);
//     // for (std::containeror<int>::iterator it = container.begin(); it != container.end(); ++it)
//     //      std::cout <<  *it << std::endl;

// }

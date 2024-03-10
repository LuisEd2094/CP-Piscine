#include <PmergeMe.hpp>
#define CONTAINER Container<T, std::allocator<T> >
#define CONTAINER_CONTAINER Container<Container<T, std::allocator<T> >, std::allocator<Container<T, std::allocator<T> > > > 

template <typename T, template <typename, typename> class Container>
void generatePairs(int *&container, CONTAINER_CONTAINER &twoPairs, std::size_t &size, bool &isOdd, int &odd)
{
    int i, j;
    for (i = 0, j = 0; i < size; i += 2, ++j)
    {
        CONTAINER temp;
        if (container[i] < container[i + 1])
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
void addFirstElemtTocontaineror(CONTAINER &container, CONTAINER_CONTAINER &twoPairs)
{
    int i = 0;

    for (typename CONTAINER_CONTAINER::iterator it = twoPairs.begin(); it != twoPairs.end(); ++it, ++i)
    {
        CONTAINER &innercontaineror = *it;
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
template <typename T, template <typename, typename> class Container>
std::vector<int> calculateJacob(CONTAINER_CONTAINER &twoPairs)
{
    std::vector<int> values; // = new std::vector<int>();
    std::size_t size = twoPairs.size();

    values.push_back(1);
    values.push_back(3);
    for (int i = 1;; ++i)
    {
        values.push_back((values[i - 1] * 2) + values[i]);
        if (values.back() >= size - 1)
            break;
    }
    return (values);
}

template <typename T, template <typename, typename> class Container>
void binaryInsertion(CONTAINER &container, CONTAINER_CONTAINER &twoPairs)
{

    if (twoPairs.size() >= 1)
    {
        int index = binarySearch(container, twoPairs[0][1], 0, container.size() - 1);
        container.insert(container.begin() + index, twoPairs[0][1]);
    }
    if (twoPairs.size() >= 2) // insert second pair
    {
        int index = binarySearch(container, twoPairs[1][1], 0, container.size() - 1);
        container.insert(container.begin() + index, twoPairs[1][1]);
    }
    /*
        int jacobsthal_diff[] =  {
            2, 2, 6, 10,

     }; */

    if (twoPairs.size() >= 3)
    {
        std::vector<int> jacobIndexs = calculateJacob(twoPairs);
        /*     int loopSize;
            for (loopSize = 0; jacobIndexs[loopSize + 1]; loopSize++){std::cout << "HOLA";}; */
        int containerIndex = 2;
        int lastIndex = 0;
        for (int i = 1;; ++i)
        {
            int startIndex;
            if (jacobIndexs[i] >= twoPairs.size())
            {
                if (jacobIndexs[i] == twoPairs.size())
                    startIndex = jacobIndexs[i] - 1;
                else
                    startIndex = (twoPairs.size() - (jacobIndexs[i - 1]) - 1) + jacobIndexs[i - 1];
            }
            else
                startIndex = jacobIndexs[i];
            int moves = startIndex - jacobIndexs[i - 1];
            /*         if (lastIndex + moves > twoPairs.size())
                        moves = twoPairs.size() - lastIndex - 2; */
            for (int j = 0; j < moves; ++j)
            {
                int end = container.size() - 1;
                int pairIndex = startIndex - j;
                int value = twoPairs[pairIndex][1];
                int start = pairIndex;
                int lowerValue = twoPairs[pairIndex][0];

                while (lowerValue < container[start])
                    start--;
                while (lowerValue > container[start])
                    start++;

                int index = binarySearch(container, value, start, end);
                container.insert(container.begin() + index, value);
            }
            if (jacobIndexs[i] >= twoPairs.size() - 1)
                break;
            containerIndex += moves;
        }
    }
}

template <typename T, template <typename, typename> class Container>
void solveMergeInsert(std::size_t argc, int *ints)
{
    if (argc < 2)
        return;
    CONTAINER container;
    int odd;
    bool isOdd = argc % 2;
    std::size_t pairSize = isOdd ? argc - 1 : argc;

    // getJacob(argc);
    // Init twoPair list to have half or half + 1 argc if argc is odd. internal containerors are size 2 int
    CONTAINER_CONTAINER twoPairs;
    generatePairs(ints, twoPairs, pairSize, isOdd, odd);
    mergeSort(twoPairs, 0, twoPairs.size() - 1);
    addFirstElemtTocontaineror(container, twoPairs);
    container.push_back(*(--((--twoPairs.end())->end()))); // push second elem of the last elemt
    twoPairs.pop_back();
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

    std::sort(temp.begin(), temp.end());
    for (int i = 0; i < argc; ++i)
    {
        std::cout << container[i] << std::endl;
        if (temp[i] != container[i])
        {
            std::cerr << "NOT SORTED" << std::endl;
            std::cerr << "with: " << argc << "numbers" << std::endl;
            for (int j = 0; j < argc; ++j)
                std::cerr << ints[j] << std::endl;
            break;
        }
    }
    std::cout << "SORTED" << std::endl;
    // Container<Container<int> > twoPairs(size % 2 == 0 ? size / 2 : (size / 2) + 1, Container<int>(2));

    // addFirstElemtTocontaineror(container, twoPairs);
    // binaryInsertion(container, twoPairs);
    // container.resize(size);
    // for (Container<int>::iterator it = container.begin(); it != container.end(); ++it)
    //      std::cout <<  *it << std::endl;
}

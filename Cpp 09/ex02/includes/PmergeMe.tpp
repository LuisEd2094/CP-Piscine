#include "PmergeMe.hpp"

#define CONTAINER Container<T, std::allocator<T> >
#define CONTAINER_CONTAINER Container<Container<T, std::allocator<T> >, std::allocator<Container<T, std::allocator<T> > > > 

template <typename T, template <typename, typename> class Container>
void generatePairs(int *&container, CONTAINER_CONTAINER &pairs, std::size_t &size, bool &isOdd, int &odd)
{
    int i, j;
    for (i = 0, j = 0; i < size; i += 2, ++j)
    {
        CONTAINER temp;
        if (container[i] < container[i + 1])
        {
            temp.push_back(container[i]);
            temp.push_back(container[i + 1]);
            pairs.push_back(temp);
        }
        else
        {
            temp.push_back(container[i + 1]);
            temp.push_back(container[i]);
            pairs.push_back(temp);
        }
    }
    if (isOdd)
        odd = container[i];
}
template <typename T, template <typename, typename> class Container>
void addFirstElemtTovector(CONTAINER &container, CONTAINER_CONTAINER &pairs)
{
    int i = 0;

    for (typename CONTAINER_CONTAINER::iterator it = pairs.begin(); it != pairs.end(); ++it, ++i)
    {
        CONTAINER &innervector = *it;
        container.push_back(*(innervector.begin()));
    }
}

template <typename T, template <typename, typename> class Container>
int binarySearch(CONTAINER &container, int value, int start, int end)
{
    if (start == end)
    {
        if (container[start] > value)
            return (start);
        else
            return (start + 1);
    }
    else if (start > end)
        return (start);
    int midPoint = (start + end) / 2;

    if (container[midPoint] < value)
        return (binarySearch(container, value, midPoint + 1, end));
    else if (container[midPoint] > value)
        return (binarySearch(container, value, start, midPoint - 1));
    else
        return (midPoint);
}
template <typename T, template <typename, typename> class Container>
std::vector<int> calculateJacob(CONTAINER_CONTAINER &pairs)
{
    std::vector<int> values;
    std::size_t size = pairs.size();

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
int getStartIndex(int i, std::vector<int>& jacobIndexs, CONTAINER_CONTAINER& pairs )
{
    if (jacobIndexs[i] >= pairs.size())
    {
        if (jacobIndexs[i] == pairs.size())
            return jacobIndexs[i] - 1;
        else
            return (pairs.size() - (jacobIndexs[i - 1]) - 1) + jacobIndexs[i - 1];
    }
    else
        return jacobIndexs[i];
}

template <typename T, template <typename, typename> class Container>
int getStart(int& pairIndex, int& lowerValue, CONTAINER& container)
{
    int start = pairIndex;
    while (lowerValue < container[start])
        start--;
    while (lowerValue > container[start])
        start++;
    return start;
}

template <typename T, template <typename, typename> class Container>
void binaryInsertion(CONTAINER& container, CONTAINER_CONTAINER& pairs)
{

    /*inserts the first two pairs to the container, so that we can now start at value 3 of the sequence
    this way the pair indexes match the 1 to 1 the values of the sequence*/
    if (pairs.size() >= 1)
    {
        int index = binarySearch(container, pairs[0][1], 0, container.size() - 1);
        container.insert(container.begin() + index, pairs[0][1]);
    }
    if (pairs.size() >= 2)
    {
        int index = binarySearch(container, pairs[1][1], 0, container.size() - 1);
        container.insert(container.begin() + index, pairs[1][1]);
    }

    /*if there are any more pairs left we can use the sequence now and finish adding them to the container*/
    if (pairs.size() >= 3)
    {
        std::vector<int> jacobIndexs = calculateJacob(pairs);
        int startIndex;
        int moves;
        int start;
        int end;
        int pairIndex;
        int value;
        int lowerValue;
        int index;

        for (int i = 1; ; ++i)
        {
            startIndex = getStartIndex(i, jacobIndexs, pairs);
            moves = startIndex - jacobIndexs[i - 1];
            for (int j = 0; j < moves; ++j)
            {
                end = container.size() - 1;
                pairIndex = startIndex - j;
                value = pairs[pairIndex][1];
                /*get the position of the lower value of the pair. Anything before it we can ignore on the binary search, reducing the size of the subContainer we will perfomn BinS on */
                start = getStart(pairIndex, pairs[pairIndex][0], container);
                index = binarySearch(container, value, start, end);
                container.insert(container.begin() + index, value);
            }
            /*Once the index is bigger than how many pairs we have, we can exit the loop*/
            if (jacobIndexs[i] >= pairs.size() - 1)
                break;
        }
    }
}
template <typename T, template <typename, typename> class Container>
void addOdd(CONTAINER& container, int& odd)
{
    int index = binarySearch(container, odd, 0, container.size() - 1);
    if (index == container.size())
        container.push_back(odd);
    else
        container.insert(container.begin() + index, odd);
}

template <typename T, template <typename, typename> class Container>
void testIfSorted(std::size_t argc, CONTAINER& container, int *ints)
{
    bool isSorted = 1;
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
            isSorted = 0;
            break;
        }
    }
    if (isSorted)
        std::cout << "SORTED" << std::endl;
}

template <typename T, template <typename, typename> class Container>
clock_t solveMergeInsert(std::size_t argc, int *ints)
{
    clock_t end;
    if (argc < 2)
        return clock();

    CONTAINER container;
    int odd;
    bool isOdd = argc % 2;
    std::size_t pairSize = isOdd ? argc - 1 : argc;
    CONTAINER_CONTAINER pairs;

    /*Generate ordered pairs from original set, then sort them in ascending order based on their lowest values */
    generatePairs(ints, pairs, pairSize, isOdd, odd);
    mergeSort(pairs, 0, pairs.size() - 1);
    /*Add the first element of each pair to the container (the smalles of each pair)
    Then add the last element of the last pair and remove that pair from the container*/
    addFirstElemtTovector(container, pairs);
    container.push_back(*(--((--pairs.end())->end())));
    pairs.pop_back();
    /*Perfomn Binary insertion to add the rest of the numbers*/ 
    binaryInsertion(container, pairs);
    /*if there is an Odd, add it*/
    if (isOdd)
        addOdd(container,odd);
    end = clock();
    int i;
    std::cout << "After: ";
    for(i = 0 ; i < 20 && i < argc; ++i)
        std::cout << container[i] << " ";
    if (i >= 20)
        std::cout << "\nContaier too big, didn't print everything";
    std::cout << std::endl;

    /*Remove comment to launch this test, it'd call the std::sort() function and check to make sure the new container is ordered.
    If not ordered it'd print to the cerr the values used and "NOT SORTED", otherwise it'd print SORTED to the cout*/
    testIfSorted(argc, container, ints);
    return end;
}

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


// 1, 1, 3, 5, 11, 21
template <typename T, template <typename, typename> class Container>
void binaryInsertion(CONTAINER&container, CONTAINER_CONTAINER& twoPairs)
{
    int jacobsthal_diff[] =  {
        2u, 2u, 6u, 10u, 22u, 42u, 86u, 170u, 342u, 682u, 1366u,
        2730u, 5462u, 10922u, 21846u, 43690u, 87382u, 174762u };
    int jjacobsthalSequence[] ={
        1, 3, 5, 11, 21
    };
    int lastIndex = 1;
    for (int i = 0; i < twoPairs.size() / 2; ++i)
    {
        int jacobIndex = jacobsthal_diff[i];
        for (int j = 0; j < jacobIndex; ++j)
        {
            int start = jjacobsthalSequence[i] + j;
            int end = container.size() - 1;
            int pairIndex = jjacobsthalSequence[i + 1] - jjacobsthalSequence[i] - j - 1;
            int value = twoPairs[pairIndex][1];
            int index = binarySearch(container, value, start, end);
            container.insert(container.begin() + index, value);

        }

    }

}


template <typename T, template <typename, typename> class Container>
void solveMergeInsert(std::size_t argc, int *ints)
{
    if (argc < 2) return ;
    CONTAINER container;
    // static constexpr std::uint_least64_t jacobsthal_diff[] = {
    //     2u, 2u, 6u, 10u, 22u, 42u, 86u, 170u, 342u, 682u, 1366u,
    //     2730u, 5462u, 10922u, 21846u, 43690u, 87382u, 174762u, 349526u, 699050u,
    //     1398102u, 2796202u, 5592406u, 11184810u, 22369622u, 44739242u, 89478486u,
    //     178956970u, 357913942u, 715827882u, 1431655766u, 2863311530u, 5726623062u,
    //     11453246122u, 22906492246u, 45812984490u, 91625968982u, 183251937962u,
    //     366503875926u, 733007751850u, 1466015503702u, 2932031007402u, 5864062014806u,
    //     11728124029610u, 23456248059222u, 46912496118442u, 93824992236886u, 187649984473770u,
    //     375299968947542u, 750599937895082u, 1501199875790165u, 3002399751580331u,
    //     6004799503160661u, 12009599006321322u, 24019198012642644u, 48038396025285288u,
    //     96076792050570576u, 192153584101141152u, 384307168202282304u, 768614336404564608u,
    //     1537228672809129216u, 3074457345618258432u, 6148914691236516864u
    // };
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
        container.insert(container.begin() + index, odd);

    }
    // int index = binarySearch(container, 3, 1, 3);
    // int value = 3;

    // container.insert(container.begin() + index, 3);
    std::cout << "hola";

    
    // Container<Container<int> > twoPairs(size % 2 == 0 ? size / 2 : (size / 2) + 1, Container<int>(2));


    // addFirstElemtTocontaineror(container, twoPairs);
    // binaryInsertion(container, twoPairs);
    // container.resize(size);
    // for (Container<int>::iterator it = container.begin(); it != container.end(); ++it)
    //      std::cout <<  *it << std::endl;

}

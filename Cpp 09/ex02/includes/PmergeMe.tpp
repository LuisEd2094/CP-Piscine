#include <iostream>

template<typename Container>
void merge(Container&  container, const int left, const int mid, const int right)
{
    const int subContOne = mid - left  + 1;
    const int subContTwo = right - mid;
    Container leftContainer(subContOne);
    Container rightContainer(subContTwo);

    for (int i = 0; i < subContOne; ++i)
        leftContainer[i] = container[left + i];
    for (int i = 0; i < subContTwo; ++i)
        rightContainer[i] = container[mid + 1 + i];

    int indxSubOne = 0, indxSubTwo = 0, indxMerge = left;

    while (indxSubOne < subContOne && indxSubTwo < subContTwo)
    {
        if (leftContainer[indxSubOne] <= rightContainer[indxSubTwo])
        {
            container[indxMerge] = leftContainer[indxSubOne];
            indxSubOne++;
        }
        else
        {
            container[indxMerge] = rightContainer[indxSubTwo];
            indxSubTwo++;
        }
        indxMerge++;

    }
    while (indxSubOne < subContOne)
    {
        container[indxMerge] = leftContainer[indxSubOne];
        indxSubOne++;
        indxMerge++;
    }

    while (indxSubTwo < subContTwo)
    {
        container[indxMerge] = rightContainer[indxSubTwo];
        indxSubTwo++;
        indxMerge++;
    }
}


template<typename Container>
void mergeSort(Container& container, const int begin, const int end)
{
    if (begin >= end)
        return;
    int mid = begin + (end - begin) / 2;
    mergeSort(container, begin, mid);
    mergeSort(container, mid + 1, end);
    merge(container, begin, mid, end);

}

template<typename Container>
void solveMergeSort(std::size_t argc, int *ints)
{
    Container container(argc);
    
    for (int i = 0; i < argc; ++i)
        container[i] = ints[i];

    mergeSort(container, 0, argc - 1);
    
    // for (int i = 0; i < argc; ++i)
    //     std::cout << container[i] << std::endl;
}

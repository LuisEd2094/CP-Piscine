#include <PmergeMe.hpp>

void generatePairs(std::vector<int>& vect, std::vector<std::vector<int> >& twoPairs, std::size_t& size, bool& isOdd)
{
    for (int i = 0, j = 0; i < size; i += 2,  ++j)
    {
        if (vect[i] <  vect[i + 1])
        {
            twoPairs[j][0] = vect[i];
            twoPairs[j][1] = vect[i + 1];
        }
        else
        {
            twoPairs[j][0] = vect[i + 1];
            twoPairs[j][1] = vect[i];  
        }

    }
    if (isOdd)
    {
        twoPairs[twoPairs.size() - 1][0] = vect[vect.size() - 1];
        twoPairs[twoPairs.size() - 1].resize(1);

    }
}

void addFirstElemtToVector(std::vector<int>&vect, std::vector<std::vector<int> >& twoPairs)
{
    int i = 0;
    for (std::vector<std::vector<int> >::iterator it = twoPairs.begin(); it != twoPairs.end(); ++it, ++i)
    {
        std::vector<int>& innerVector = *it;
        vect[i] = *(innerVector.begin());
    }
    if ((--twoPairs.end())->size() > 1)
        vect[i] = *(--((--twoPairs.end())->end()));
}

int binarySearch(std::vector<int>&vect, int value, int start, int end)
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

// We have the first twoPairs.size() elemts sorted inside vector. We need to keep track of this subVector to know where to look for
// the binary Inserton
void binaryInsertion(std::vector<int>&vect, std::vector<std::vector<int> >& twoPairs)
{
    std::size_t subVectSize = twoPairs.size();
    for (int i = 0; i < twoPairs.size(); ++i)
    {
        if (twoPairs[i].size() > 1) //Protect the odd
        {
            int index = binarySearch(vect, twoPairs[i][1], 0, subVectSize);
            vect.insert(vect.begin() + index, twoPairs[i][1]);
            subVectSize++;
        }
    }


}

void solverMergeInsertVector(std::vector<int>& vect)
{
    std::size_t size = vect.size();
    bool        isOdd = size % 2;

    if (size < 2) return ;
    //Init twoPair list to have half or half + 1 argc if argc is odd. internal vectors are size 2 int
    std::vector<std::vector<int> > twoPairs(size % 2 == 0 ? size / 2 : (size / 2) + 1, std::vector<int>(2));


    generatePairs(vect, twoPairs, size, isOdd);    
    mergeSort(twoPairs, 0, twoPairs.size() - 1);
    addFirstElemtToVector(vect, twoPairs);
    binaryInsertion(vect, twoPairs);
    vect.resize(size);
    // for (std::vector<int>::iterator it = vect.begin(); it != vect.end(); ++it)
    //      std::cout <<  *it << std::endl;

}

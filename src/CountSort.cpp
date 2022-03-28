#include "CountSort.h"

#include <iostream>
CountSort::CountSort(std::vector<Element>& elems) : SortingAlgorithm(elems)
{
}

int CountSort::getMax()
{
    int max = 0;
    
    for(size_t i = 0; i < elems->size(); i++)
    {
        if(elems->at(i).height > max)
        {
            max = elems->at(i).height;
        }
    }
    return max;
}

void CountSort::_sort()
{
    std::vector<Element> output;
    output.reserve(elems->size());

    int max = getMax();
    int count[max + 1];

    for(int i = 0; i < max + 1; i++)
        count[i] = 0;

    for(size_t i = 0; i < elems->size(); i++)
    {
        int index = elems->at(i).height;
        count[index] ++;
    }

    for(int i = 1; i < max; i++)
        count[i] += count[i-1];

    for(int i = elems->size()-1; i >= 0; i--)
    {
        int index = elems->at(i).height;
        output[count[index] - 1] =  elems->at(i);
        count[index]--;
    }
    
    for(size_t i = 0; i < elems->size(); i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        elems->at(i) = output[i];
    }
}
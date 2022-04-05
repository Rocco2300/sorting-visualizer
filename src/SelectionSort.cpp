#include "SelectionSort.h"

SelectionSort::SelectionSort(std::vector<Element>& elems) : SortingAlgorithm(elems)
{
}

void SelectionSort::_sort()
{
    for(size_t i = 0; i < elems->size(); i++)
    {
        int index = i;

        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        for(size_t j = i+1; j < elems->size(); j++)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(delay));
            if(compare(elems->at(index).height, elems->at(j).height))
                index = j;
        }

        std::swap(elems->at(i), elems->at(index));
    }
}
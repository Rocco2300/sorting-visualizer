#include "SelectionSort.h"

SelectionSort::SelectionSort(std::vector<Element>& elems) : SortingAlgorithm(elems)
{
}

void SelectionSort::_sort()
{
    for(size_t i = 0; i < elems->size(); i++)
    {
        int minI = i;

        std::this_thread::sleep_for(std::chrono::milliseconds(5));
        for(size_t j = i+1; j < elems->size(); j++)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
            if(elems->at(j).height < elems->at(minI).height)
                minI = j;
        }

        std::swap(elems->at(i), elems->at(minI));
    }
}
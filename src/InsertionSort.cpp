#include "InsertionSort.h"

InsertionSort::InsertionSort(std::vector<Element>& elems) : SortingAlgorithm(elems)
{
}

void InsertionSort::_sort()
{
    for(size_t i = 1; i < elems->size(); i++)
    {
        auto key = elems->at(i);
        int j = i - 1;

        while(j >= 0 && elems->at(j).height > key.height)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
            elems->at(j+1) = elems->at(j);
            j--;
        }
        elems->at(j+1) = key;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}
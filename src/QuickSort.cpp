#include "QuickSort.h"

QuickSort::QuickSort(std::vector<Element>& elems) : SortingAlgorithm(elems)
{
}

void QuickSort::quickSort(int low, int high)
{
    if(low < high)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        int pivot = partition(low, high);

        quickSort(low, pivot-1);
        quickSort(pivot+1, high);
    }
}

int QuickSort::partition(int low, int high)
{
    int pivot = elems->at(high).height;
    int i = (low - 1);

    for(int j = low; j < high; j++)
    {
        if(elems->at(j).height < pivot)
        {
            i++;
            std::swap(elems->at(i), elems->at(j));
        }
    }
    std::swap(elems->at(i+1), elems->at(high));
    return i+1;
}

void QuickSort::_sort()
{
    quickSort(0, elems->size()-1);
}
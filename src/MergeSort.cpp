#include "MergeSort.h"

MergeSort::MergeSort(std::vector<Element>& elems) : SortingAlgorithm(elems)
{
}

void MergeSort::merge(int low, int mid, int high)
{
    int sizeOne = mid - low + 1;
    int sizeTwo = high - mid;

    std::vector<Element> one;
    std::vector<Element> two;
    one.reserve(sizeOne);
    two.reserve(sizeTwo);

    for(int i = 0; i < sizeOne; i++)
        one[i] = elems->at(low + i);
    for(int j = 0; j < sizeTwo; j++)
        two[j] = elems->at(mid + 1 + j);

    int i = 0,
        j = 0,
        k = low;

    while(i < sizeOne && j < sizeTwo)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        if(one[i].height <= two[j].height)
            elems->at(k++) = one[i++];
        else
            elems->at(k++) = two[j++];
    }

    while(i < sizeOne)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        elems->at(k++) = one[i++];
    }

    while(j < sizeTwo)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));

        elems->at(k++) = two[j++];
    }
}

void MergeSort::mergeSort(int low, int high)
{
    if(low >= high)
        return;
    
    int mid = low + (high - low) / 2;

        std::this_thread::sleep_for(std::chrono::milliseconds(1));

    mergeSort(low, mid);
    mergeSort(mid+1, high);
    merge(low, mid, high);
}

void MergeSort::_sort()
{
    mergeSort(0, elems->size()-1);
}
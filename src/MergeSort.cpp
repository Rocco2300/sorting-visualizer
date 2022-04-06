#include "MergeSort.h"

MergeSort::MergeSort()
{
}

void MergeSort::merge(ElementList& elems, int low, int mid, int high)
{
    int sizeOne = mid - low + 1;
    int sizeTwo = high - mid;

    std::vector<Element> one;
    std::vector<Element> two;
    one.reserve(sizeOne);
    two.reserve(sizeTwo);

    for(int i = 0; i < sizeOne; i++)
        one[i] = elems.at(low + i);
    for(int j = 0; j < sizeTwo; j++)
        two[j] = elems.at(mid + 1 + j);

    int i = 0,
        j = 0,
        k = low;

    while(i < sizeOne && j < sizeTwo)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        if(one[i].height < two[j].height)
            elems.at(k++) = one[i++];
        else
            elems.at(k++) = two[j++];
    }

    while(i < sizeOne)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        elems.at(k++) = one[i++];
    }

    while(j < sizeTwo)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));

        elems.at(k++) = two[j++];
    }
}

void MergeSort::mergeSort(ElementList& elems, int low, int high)
{
    if(low >= high)
        return;
    
    int mid = low + (high - low) / 2;

        std::this_thread::sleep_for(std::chrono::milliseconds(delay));

    mergeSort(elems, low, mid);
    mergeSort(elems, mid+1, high);
    merge(elems, low, mid, high);
}

void MergeSort::_sort(ElementList& elems, bool desc)
{
    mergeSort(elems, 0, elems.size()-1);
}
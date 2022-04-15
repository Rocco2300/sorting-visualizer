#include "Constants.h"

MergeSort::MergeSort()
{
}

bool MergeSort::compare(int a, int b, bool desc)
{
    if(!desc)
        return a < b;
    else
        return a > b;
}

void MergeSort::selectRange(ElementList& elems, int low, int high)
{
    mutex.lock();
    for(int i = low; i <= high; i++)
    {
        elems[i].color = RANGE_COLOR;
        range.push_back(&elems[i]);
    }
    mutex.unlock();
}

void MergeSort::unselectRange(ElementList& elems)
{
    mutex.lock();
    for(int i = range.size()-1; i >= 0; i--)
    {
        if(range[i] >= &elems[0] && range[i] <= &elems[elems.size()-1])
        {
            range[i]->color = sf::Color::White;
            range.erase(range.begin() + i);
        }
    }
    mutex.unlock();
}

void MergeSort::merge(ElementList& elems, int low, int mid, int high, bool desc)
{
    selectRange(elems, low, high);

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
        if(compare(one[i].height, two[j].height, desc))
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

void MergeSort::mergeSort(ElementList& elems, int low, int high, bool desc)
{
    if(low >= high)
        return;
    
    unselectRange(elems);
    
    int mid = low + (high - low) / 2;

        std::this_thread::sleep_for(std::chrono::milliseconds(delay));

    mergeSort(elems, low, mid, desc);
    mergeSort(elems, mid+1, high, desc);
    merge(elems, low, mid, high, desc);
    unselectRange(elems);
}

void MergeSort::_sort(ElementList& elems, bool desc)
{
    mergeSort(elems, 0, elems.size()-1, desc);
}
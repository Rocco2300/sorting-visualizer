#include "QuickSort.h"

#include "Constants.h"

#include <cmath>
#include <iostream>

QuickSort::QuickSort()
{
}

bool QuickSort::compare(int a, int b, bool desc)
{
    if(!desc)
        return a < b;
    else
        return a > b;
}

void QuickSort::selectElements(ElementList& elems, int low, int high)
{
    mutex.lock();

    for(int i = low; i < high; i++)
    {
        elems[i].color = RANGE_COLOR;
        range.push_back(&elems[i]);
    }
    elems[high].color = SELECTED_COLOR;
    range.push_back(&elems[high]);

    mutex.unlock();
}

void QuickSort::unselectElements(ElementList& elems)
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

void QuickSort::quickSort(ElementList& elems, int low, int high, bool desc)
{
    unselectElements(elems);

    if(low < high)
    {
        int pivot = lomutoPartition(elems, low, high, desc);

        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        quickSort(elems, low, pivot-1, desc);
        quickSort(elems, pivot+1, high, desc);
    }

    unselectElements(elems);
}

int QuickSort::lomutoPartition(ElementList& elems, int low, int high, bool desc)
{
    selectElements(elems, low, high);

    int pivot = elems.at(high).height;
    int i = (low - 1);

    for(int j = low; j < high; j++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        if(compare(elems.at(j).height, pivot, desc))
        {
            i++;
            std::swap(elems.at(i), elems.at(j));
        }
    }
    std::swap(elems.at(i+1), elems.at(high));
    return i+1;
}

// int QuickSort::hoarePartition(int low, int high)
// {
//     int pivot = elems.at( std::floor((low + high) / 2) ).height;
//     // int pivot = elems.at(low).height;

//     int i = low - 1;
//     int j = high + 1;

//     while(true)
//     {
//         do 
//         { 
//             i++; 
//         } while (elems.at(i).height < pivot);
        
//         do 
//         { 
//             j--; 
//         } while (elems.at(j).height > pivot);

//         if(i >= j) 
//         {
//             return j;
//         }

//         std::swap(elems.at(i), elems.at(j));
//     }
// }

void QuickSort::_sort(ElementList& elems, bool desc)
{
    quickSort(elems, 0, elems.size()-1, desc);
}
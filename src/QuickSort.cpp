#include "QuickSort.h"

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

void QuickSort::quickSort(ElementList& elems, int low, int high, bool desc)
{
    if(low < high)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        int pivot = lomutoPartition(elems, low, high, desc);
        elems.at(pivot).color = sf::Color::Red;

        quickSort(elems, low, pivot-1, desc);
        quickSort(elems, pivot+1, high, desc);
        elems.at(pivot).color = sf::Color::White;
    }
}

int QuickSort::lomutoPartition(ElementList& elems, int low, int high, bool desc)
{
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
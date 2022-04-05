#include "QuickSort.h"

#include <cmath>
#include <iostream>

QuickSort::QuickSort(std::vector<Element>& elems) : SortingAlgorithm(elems)
{
}

void QuickSort::quickSort(int low, int high)
{
    if(low < high)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        int pivot = lomutoPartition(low, high);
        elems->at(pivot).color = sf::Color::Red;

        quickSort(low, pivot-1);
        quickSort(pivot+1, high);
        elems->at(pivot).color = sf::Color::White;
    }
}

int QuickSort::lomutoPartition(int low, int high)
{
    int pivot = elems->at(high).height;
    int i = (low - 1);

    for(int j = low; j < high; j++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        if(compare(pivot, elems->at(j).height))
        {
            i++;
            std::swap(elems->at(i), elems->at(j));
        }
    }
    std::swap(elems->at(i+1), elems->at(high));
    return i+1;
}

int QuickSort::hoarePartition(int low, int high)
{
    int pivot = elems->at( std::floor((low + high) / 2) ).height;
    // int pivot = elems->at(low).height;

    int i = low - 1;
    int j = high + 1;

    while(true)
    {
        do 
        { 
            i++; 
        } while (elems->at(i).height < pivot);
        
        do 
        { 
            j--; 
        } while (elems->at(j).height > pivot);

        if(i >= j) 
        {
            return j;
        }

        std::swap(elems->at(i), elems->at(j));
    }
}

void QuickSort::_sort()
{
    quickSort(0, elems->size()-1);
}
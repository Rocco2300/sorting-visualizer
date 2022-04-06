#include "SelectionSort.h"

SelectionSort::SelectionSort()
{
}

void SelectionSort::_sort(ElementList& elems, bool desc)
{
    for(size_t i = 0; i < elems.size(); i++)
    {
        int index = i;

        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        for(size_t j = i+1; j < elems.size(); j++)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(delay));
            if( elems.at(j).height < elems.at(index).height)
                index = j;
        }

        std::swap(elems.at(i), elems.at(index));
    }
}
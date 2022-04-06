#include "InsertionSort.h"

InsertionSort::InsertionSort()
{
}

void InsertionSort::_sort(ElementList& elems, bool desc)
{
    for(size_t i = 1; i < elems.size(); i++)
    {
        auto key = elems.at(i);
        int j = i - 1;

        while(j >= 0 && key.height < elems.at(j).height)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(delay));
            elems.at(j+1) = elems.at(j);
            j--;
        }
        elems.at(j+1) = key;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
}
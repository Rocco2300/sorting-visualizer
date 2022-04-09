#include "InsertionSort.h"

InsertionSort::InsertionSort()
{
}

bool InsertionSort::compare(int a, int b, bool desc)
{
    if(!desc)
        return a < b;
    else
        return a > b;
}

void InsertionSort::_sort(ElementList& elems, bool desc)
{
    for(size_t i = 1; i < elems.size(); i++)
    {
        auto key = elems.at(i);
        int j = i - 1;

        while(j >= 0 && compare(key.height, elems.at(j).height, desc))
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(delay));
            elems.at(j+1) = elems.at(j);
            j--;
        }
        elems.at(j+1) = key;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
}
#include "Constants.h"

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
        elems.at(i).color = SELECTED_COLOR;
        auto key = elems.at(i);
        int j = i - 1;  

        while(j >= 0 && compare(key.height, elems.at(j).height, desc))
        {
            elems.at(j).color = SCROLL_COLOR;
            std::this_thread::sleep_for(std::chrono::milliseconds(delay));
            elems.at(j+1) = elems.at(j);
            j--;
            elems.at(j+2).color = sf::Color::White;
        }
        elems.at(j+1) = key;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        elems.at(j+1).color = sf::Color::White;
    }
}
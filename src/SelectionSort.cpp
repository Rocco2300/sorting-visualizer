#include "Constants.h"

SelectionSort::SelectionSort()
{
}

bool SelectionSort::compare(int a, int b, bool desc)
{
    if(!desc)
        return a < b;
    else 
        return a > b;
}

void SelectionSort::_sort(ElementList& elems, bool desc)
{
    for(size_t i = 0; i < elems.size(); i++)
    {
        int index = i;
        elems[index].color = SELECTED_COLOR;

        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        for(size_t j = i+1; j < elems.size(); j++)
        {
            elems[j].color = SCROLL_COLOR1;

            std::this_thread::sleep_for(std::chrono::milliseconds(delay));
            if(compare(elems.at(j).height, elems.at(index).height, desc))
            {
                elems[index].color = sf::Color::White;
                index = j;
                elems[index].color = SELECTED_COLOR;
            }
            else
                elems[j].color = sf::Color::White;
        }

        elems[index].color = sf::Color::White;
        std::swap(elems.at(i), elems.at(index));
    }
}
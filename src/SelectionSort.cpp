#include "Constants.h"

SelectionSort::SelectionSort()
{
}

void SelectionSort::_sort(ElementList& elems, bool desc)
{
    for(size_t i = 0; i < elems.size(); i++)
    {
        int index = i;
        elems[index].setFillColor(SELECTED_COLOR);

        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        for(size_t j = i+1; j < elems.size(); j++)
        {
            elems[j].setFillColor(SCROLL_COLOR);

            std::this_thread::sleep_for(std::chrono::milliseconds(delay));
            if(compare(elems[j], elems[index], desc))
            {
                elems[index].setFillColor(sf::Color::White);
                index = j;
                elems[index].setFillColor(SELECTED_COLOR);
            }
            else
                elems[j].setFillColor(sf::Color::White);
        }

        elems[index].setFillColor(sf::Color::White);
        Element::swap(elems[i], elems[index]);
    }
}
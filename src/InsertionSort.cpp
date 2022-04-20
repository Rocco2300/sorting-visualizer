#include "Constants.h"

InsertionSort::InsertionSort()
{
}

void InsertionSort::_sort(ElementList& elems, bool desc)
{
    for(size_t i = 1; i < elems.size(); i++)
    {
        elems[i].setFillColor(SELECTED_COLOR);
        auto key = elems[i];
        int j = i - 1;  

        while(j >= 0 && compare(key, elems[j], desc))
        {
            // elems.at(j).color = SCROLL_COLOR;
            elems[j].setFillColor(SCROLL_COLOR);
            elems[j+1] = elems[j];
            j--;

            std::this_thread::sleep_for(std::chrono::milliseconds(delay));

            // elems.at(j+2).color = sf::Color::White;
            elems[j+2].setFillColor(sf::Color::White);
        }

        elems[j+1] = key;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        elems[j+1].setFillColor(sf::Color::White);
    }
}
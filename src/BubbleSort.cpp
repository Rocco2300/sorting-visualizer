#include "Constants.h"

BubbleSort::BubbleSort()
{
}

void BubbleSort::bubbleSort(ElementList& elems, bool desc)
{
    for(size_t i = 0; i < elems.size()-1; i++)
    {
        for(size_t j = 0; j < elems.size()-i-1; j++)
        {
            elems[j]().setFillColor(SCROLL_COLOR);
            elems[j+1]().setFillColor(SCROLL_COLOR);

            // elems[j] < elems[j+1]
            if(compare(elems[j+1], elems[j], desc))
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(delay));
                Element::swap(elems.at(j), elems.at(j+1));
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(delay));

            elems[j]().setFillColor(sf::Color::White);
            elems[j+1]().setFillColor(sf::Color::White);
        }

    }
} 

void BubbleSort::_sort(ElementList& elems, bool desc)
{
    bubbleSort(elems, desc);
}
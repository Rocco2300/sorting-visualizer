#include "Constants.h"

BubbleSort::BubbleSort()
{
}

bool BubbleSort::compare(int a, int b, bool desc)
{
    if(!desc)
        return a > b;
    else
        return a < b;
}

void BubbleSort::bubbleSort(ElementList& elems, bool desc)
{
    for(size_t i = 0; i < elems.size()-1; i++)
    {
        for(size_t j = 0; j < elems.size()-i-1; j++)
        {
            elems[j].color = SCROLL_COLOR;
            elems[j+1].color = SCROLL_COLOR;

            if(compare(elems.at(j).height, elems.at(j+1).height, desc))
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(delay));
                std::swap(elems.at(j), elems.at(j+1));
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(delay));

            elems[j].color = sf::Color::White;
            elems[j+1].color = sf::Color::White;
        }

    }
} 

void BubbleSort::_sort(ElementList& elems, bool desc)
{
    bubbleSort(elems, desc);
}
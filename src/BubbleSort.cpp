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
            if(compare(elems.at(j).height, elems.at(j+1).height, desc))
            {
                elems.at(j).color = SELECTED_COLOR;
                std::swap(elems.at(j), elems.at(j+1));
            }
            else
                elems.at(j).color = sf::Color::White;
            std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        }
        elems.at(elems.size()-i-1).color = sf::Color::White;
    }
} 

void BubbleSort::_sort(ElementList& elems, bool desc)
{
    bubbleSort(elems, desc);
}
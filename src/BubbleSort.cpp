#include "Constants.h"

BubbleSort::BubbleSort()
{
}

void BubbleSort::bubbleSortAsc(ElementList& elems)
{
    for(size_t i = 0; i < elems.size()-1; i++)
    {
        for(size_t j = 0; j < elems.size()-i-1; j++)
        {
            if(elems.at(j).height > elems.at(j+1).height)
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

void BubbleSort::bubbleSortDesc(ElementList& elems)
{
    for(size_t i = 0; i < elems.size()-1; i++)
    {
        for(size_t j = 0; j < elems.size()-i-1; j++)
        {
            if(elems.at(j).height < elems.at(j+1).height)
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
    if(!desc)
        bubbleSortAsc(elems);
    else 
        bubbleSortDesc(elems);
}
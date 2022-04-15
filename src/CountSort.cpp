#include "Constants.h"

CountSort::CountSort()
{
}

int CountSort::getMax(ElementList& elems)
{
    int max = 0;
    
    for(size_t i = 0; i < elems.size(); i++)
    {
        elems.at(i).color = SELECTED_COLOR;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        if(elems.at(i).height > max)
        {
            max = elems.at(i).height;
        }
        elems.at(i).color = sf::Color::White;
    }
    return max;
}

void CountSort::_sort(ElementList& elems, bool desc)
{
    std::vector<Element> output;
    output.reserve(elems.size());

    int max = getMax(elems);
    int count[max + 1];

    for(int i = 0; i <= max; i++)
        count[i] = 0;

    for(size_t i = 0; i < elems.size(); i++)
    {
        int index = elems.at(i).height;
        count[index] ++;
    }

    for(int i = 1; i <= max; i++)
        count[i] += count[i-1];

    for(int i = elems.size()-1; i >= 0; i--)
    {
        int index = elems.at(i).height;
        int outputIndex = desc? max - count[index] - (max - elems.size())
                                : count[index] - 1;

        output[outputIndex] =  elems.at(i);
        elems.at(i).color = SELECTED_COLOR;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        count[index]--;
        elems.at(i).color = sf::Color::White;
    }
    
    for(size_t i = 0; i < elems.size(); i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        elems.at(i) = output[i];
    }
}
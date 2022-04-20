#include "Constants.h"

CountSort::CountSort()
{
}

int CountSort::getMax(ElementList& elems)
{
    int max = 0;
    
    for(size_t i = 0; i < elems.size(); i++)
    {
        elems[i].setFillColor(SELECTED_COLOR);
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));

        if(elems[i].getHeight() > max)
        {
            max = elems[i].getHeight();
        }
        elems[i].setFillColor(sf::Color::White);
    }
    return max;
}

void CountSort::_sort(ElementList& elems, bool desc)
{
    ElementList output;
    output.reserve(elems.size());
    output.resize(elems.size());

    int max = getMax(elems);
    int count[max + 1];

    for(int i = 0; i <= max; i++)
        count[i] = 0;

    for(size_t i = 0; i < elems.size(); i++)
    {
        int index = elems[i].getHeight();
        count[index] ++;
    }

    for(int i = 1; i <= max; i++)
        count[i] += count[i-1];

    for(int i = elems.size()-1; i >= 0; i--)
    {
        int index = elems[i].getHeight();
        int outputIndex = desc? max - count[index] - (max - elems.size())
                                : count[index] - 1;

        output[outputIndex] = elems[i];
        elems[i].setFillColor(SELECTED_COLOR);

        std::this_thread::sleep_for(std::chrono::milliseconds(delay));

        count[index]--;
        elems[i].setFillColor(sf::Color::White);
    }
    
    for(size_t i = 0; i < elems.size(); i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        elems[i] = output[i];
    }
}
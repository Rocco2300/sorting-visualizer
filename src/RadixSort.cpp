#include "Constants.h"

#include <cmath>
#include <iostream>

RadixSortLSD::RadixSortLSD()
{
}

int RadixSortLSD::getMax(ElementList& elems)
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

void RadixSortLSD::countSortAsc(ElementList& elems, int exp)
{
    std::vector<Element> output;
    output.reserve(elems.size());

    int count[10] = { 0 };

    for(size_t i = 0; i < elems.size(); i++)
    {
        int height = elems.at(i).height;
        int index = (height / exp) % 10;

        count[index]++;
    }

    for(int i = 1; i <= 9; i++)
        count[i] += count[i-1];

    for(int i = elems.size()-1; i >= 0; i--)
    {
        int height = elems.at(i).height;
        int index = (height / exp) % 10;

        output[count[index] - 1] = elems.at(i);
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

void RadixSortLSD::countSortDesc(ElementList& elems, int exp)
{
    std::vector<Element> output;
    output.reserve(elems.size());

    int count[10] = { 0 };

    for(size_t i = 0; i < elems.size(); i++)
    {
        int height = elems.at(i).height;
        int index = (height / exp) % 10;

        count[index]++;
    }

    for(int i = 1; i <= 9; i++)
        count[i] += count[i-1];

    for(size_t i = 0; i < elems.size(); i++)
    {
        int height = elems.at(i).height;
        int index = (height / exp) % 10;

        output[9 - count[index] - (9 - elems.size())] = elems.at(i);
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

void RadixSortLSD::_sort(ElementList& elems, bool desc)
{
    int max = getMax(elems);

    for(int exp = 1; max / exp > 0; exp *= 10)
    {
        if(!desc)
            countSortAsc(elems, exp);
        else
            countSortDesc(elems, exp);
    }
}
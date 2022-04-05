#include "RadixSort.h"

#include <iostream>
CountSort::CountSort(std::vector<Element>& elems) : SortingAlgorithm(elems)
{
}

int CountSort::getMax()
{
    int max = 0;
    
    for(size_t i = 0; i < elems->size(); i++)
    {
        elems->at(i).color = sf::Color::Red;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        if(elems->at(i).height > max)
        {
            max = elems->at(i).height;
        }
        elems->at(i).color = sf::Color::White;
    }
    return max;
}

void CountSort::_sort()
{
    std::vector<Element> output;
    output.reserve(elems->size());

    int max = getMax();
    int count[max + 1];

    for(int i = 0; i <= max; i++)
        count[i] = 0;

    for(size_t i = 0; i < elems->size(); i++)
    {
        int index = elems->at(i).height;
        count[index] ++;
    }

    for(int i = 1; i <= max; i++)
        count[i] += count[i-1];

    for(int i = elems->size()-1; i >= 0; i--)
    {
        int index = elems->at(i).height;
        int outputIndex = descending? max - count[index] - (max - elems->size())
                                    : count[index] - 1;

        output[outputIndex] =  elems->at(i);
        elems->at(i).color = sf::Color::Red;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        count[index]--;
        elems->at(i).color = sf::Color::White;
    }
    
    for(size_t i = 0; i < elems->size(); i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        elems->at(i) = output[i];
    }
}

RadixSort::RadixSort(std::vector<Element>& elems) : SortingAlgorithm(elems)
{
}

int RadixSort::getMax()
{
    int max = 0;
    
    for(size_t i = 0; i < elems->size(); i++)
    {
        elems->at(i).color = sf::Color::Red;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        if(elems->at(i).height > max)
        {
            max = elems->at(i).height;
        }
        elems->at(i).color = sf::Color::White;
    }
    return max;
}

void RadixSort::countSortAsc(int exp)
{
    std::vector<Element> output;
    output.reserve(elems->size());

    int count[10] = { 0 };

    for(size_t i = 0; i < elems->size(); i++)
    {
        int height = elems->at(i).height;
        int index = (height / exp) % 10;

        count[index]++;
    }

    for(int i = 1; i <= 9; i++)
        count[i] += count[i-1];

    for(int i = elems->size()-1; i >= 0; i--)
    {
        int height = elems->at(i).height;
        int index = (height / exp) % 10;

        output[count[index] - 1] = elems->at(i);
        elems->at(i).color = sf::Color::Red;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        count[index]--;
        elems->at(i).color = sf::Color::White;
    }

    for(size_t i = 0; i < elems->size(); i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        elems->at(i) = output[i];
    }
}

void RadixSort::countSortDesc(int exp)
{
    std::vector<Element> output;
    output.reserve(elems->size());

    int count[10] = { 0 };

    for(size_t i = 0; i < elems->size(); i++)
    {
        int height = elems->at(i).height;
        int index = (height / exp) % 10;

        count[index]++;
    }

    for(int i = 1; i <= 9; i++)
        count[i] += count[i-1];

    for(size_t i = 0; i < elems->size(); i++)
    {
        int height = elems->at(i).height;
        int index = (height / exp) % 10;

        output[9 - count[index] - (9 - elems->size())] = elems->at(i);
        elems->at(i).color = sf::Color::Red;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        count[index]--;
        elems->at(i).color = sf::Color::White;
    }

    for(size_t i = 0; i < elems->size(); i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        elems->at(i) = output[i];
    }
}

void RadixSort::_sort()
{
    int max = getMax();

    for(int exp = 1; max / exp > 0; exp *= 10)
    {
        if(!descending)
            countSortAsc(exp);
        else
            countSortDesc(exp);
    }
}
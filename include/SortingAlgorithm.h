#pragma once

#include <SFML/Graphics.hpp>
#include <thread>

struct Element
{
    float height;
    sf::Color color;
};

class SortingAlgorithm
{
protected:
    std::vector<Element>* elems;
public:
    SortingAlgorithm(std::vector<Element>& elems);
    virtual ~SortingAlgorithm() { }
    virtual void sort() { }
};
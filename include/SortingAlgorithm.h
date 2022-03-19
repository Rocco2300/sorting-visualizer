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
    bool finished;
    std::vector<Element>* elems;
public:
    SortingAlgorithm(std::vector<Element>& elems);
    virtual ~SortingAlgorithm() { }
    void sort();
    bool isFinished();
protected:
    virtual void _sort() { }
};
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
    int delay;
public:
    SortingAlgorithm(std::vector<Element>& elems);
    virtual ~SortingAlgorithm() { }
    virtual void sort();
    bool isFinished();
    void setDelay(int delay);
protected:
    virtual void _sort() { }
};
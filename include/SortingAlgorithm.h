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
    bool stopping;
    std::vector<Element>* elems;
public:
    SortingAlgorithm(std::vector<Element>& elems);
    virtual ~SortingAlgorithm() { }
    virtual void sort();
    bool isFinished();
    void stop();
protected:
    virtual void _sort() { }
};
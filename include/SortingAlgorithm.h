#pragma once

#include <SFML/Graphics.hpp>
#include <thread>

struct Element
{
    float height;
    sf::Color color;
};

typedef std::vector<Element> ElementList;

class SortingAlgorithm
{
protected:
    bool finished;
    int delay;
public:
    SortingAlgorithm();
    virtual ~SortingAlgorithm() { }
    virtual void sort(ElementList& elems, bool desc);
    bool isFinished();
    void setDelay(int delay);
protected:
    virtual void _sort(ElementList& elems, bool desc) { }
};
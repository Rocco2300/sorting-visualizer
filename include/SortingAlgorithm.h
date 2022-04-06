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
    int delay;
public:
    SortingAlgorithm();
    virtual ~SortingAlgorithm() { }
    virtual bool sort(ElementList& elems, bool desc);
    bool isFinished();
    void setDelay(int delay);
protected:
    virtual void _sort(ElementList& elems, bool desc) { }
};
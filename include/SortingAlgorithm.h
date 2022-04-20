#pragma once

#include <SFML/Graphics.hpp>
#include <thread>

// struct Element
// {
//     float height;
//     sf::Color color;
// };

typedef sf::RectangleShape Element;
typedef std::unique_ptr<Element> ElementPtr;
typedef std::vector<ElementPtr> ElementList;

bool operator<(const ElementPtr& a, const ElementPtr& b);
bool operator>(const ElementPtr& a, const ElementPtr& b);

class SortingAlgorithm
{
protected:
    int delay;
public:
    SortingAlgorithm();
    virtual ~SortingAlgorithm() { }
    virtual void sort(ElementList& elems, bool desc);

    void shuffle(ElementList& elems);
    void setDelay(int delay);
protected:
    virtual void _sort(ElementList& elems, bool desc) { }

    bool compare(const ElementPtr& a, const ElementPtr& b, bool desc);
    void swap(ElementPtr& a, ElementPtr& b);
};
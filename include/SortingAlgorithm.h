#pragma once

#include "Element.h"

#include <thread>

typedef std::vector<Element> ElementList;

class SortingAlgorithm
{
protected:
    int delay;
public:
    SortingAlgorithm();
    virtual ~SortingAlgorithm() { }
    virtual void sort(ElementList& elems, bool desc);

    void shuffle(ElementList& elems, int delay);
    void setDelay(int delay);
protected:
    virtual void _sort(ElementList& elems, bool desc) { }

    bool compare(const Element& a, const Element& b, bool desc);
};
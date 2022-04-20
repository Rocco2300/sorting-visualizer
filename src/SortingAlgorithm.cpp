#include "SortingAlgorithm.h"

SortingAlgorithm::SortingAlgorithm()
{
    this->delay = 10;
}

void SortingAlgorithm::sort(ElementList& elems, bool desc)
{
    _sort(elems, desc);
    return;
}

void SortingAlgorithm::shuffle(ElementList& elems)
{
    for(int i = elems.size()-1; i > 0; i--)
    {
        int randIndex = (i != 1) ? rand() % (i-1) : 0;
        Element::swap(elems[i], elems[randIndex]);
    }
}

void SortingAlgorithm::setDelay(int delay)
{
    this->delay = delay;
}

bool SortingAlgorithm::compare(const Element& a, const Element& b, bool desc)
{
    if(!desc)
        return a < b;
    else
        return a > b;
}

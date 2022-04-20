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
        swap(elems[i], elems[randIndex]);
    }
}

void SortingAlgorithm::setDelay(int delay)
{
    this->delay = delay;
}

bool operator<(const ElementPtr& a, const ElementPtr& b)
{
    return a->getSize().y < b->getSize().y;
}

bool operator>(const ElementPtr& a, const ElementPtr& b)
{
    return a->getSize().y > b->getSize().y;
}

bool SortingAlgorithm::compare(const ElementPtr& a, const ElementPtr& b, bool desc)
{
    if(!desc)
        return a < b;
    else
        return a > b;
}

void SortingAlgorithm::swap(ElementPtr& a, ElementPtr& b)
{
    auto pos = a->getPosition();
    a->setPosition(b->getPosition());
    b->setPosition(pos);

    auto aux = std::move(a);
    a = std::move(b);
    b = std::move(aux);
}

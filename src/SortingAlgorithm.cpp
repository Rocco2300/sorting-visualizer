#include "SortingAlgorithm.h"

SortingAlgorithm::SortingAlgorithm()
{
    this->delay = 10;
}

void SortingAlgorithm::sort(std::vector<Element>& elems, bool desc)
{
    _sort(elems, desc);
    return;
}

void SortingAlgorithm::setDelay(int delay)
{
    this->delay = delay;
}

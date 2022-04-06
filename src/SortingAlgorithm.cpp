#include "SortingAlgorithm.h"

SortingAlgorithm::SortingAlgorithm()
{
    this->delay = 10;
}

bool SortingAlgorithm::sort(std::vector<Element>& elems, bool desc)
{
    _sort(elems, desc);
    return true;
}

void SortingAlgorithm::setDelay(int delay)
{
    this->delay = delay;
}

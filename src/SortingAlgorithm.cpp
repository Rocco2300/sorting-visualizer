#include "SortingAlgorithm.h"

SortingAlgorithm::SortingAlgorithm(std::vector<Element>& elems)
{
    this->elems = &elems;
    this->finished = false;
    this->delay = 10;
}

void SortingAlgorithm::sort()
{
    _sort();
    finished = true;
}

bool SortingAlgorithm::isFinished()
{
    return finished;
}

void SortingAlgorithm::setDelay(int delay)
{
    this->delay = delay;
}

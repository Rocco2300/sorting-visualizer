#include "SortingAlgorithm.h"

SortingAlgorithm::SortingAlgorithm()
{
    this->finished = true;
    this->delay = 10;
}

void SortingAlgorithm::sort(std::vector<Element>& elems, bool desc)
{
    finished = false;
    _sort(elems, desc);
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

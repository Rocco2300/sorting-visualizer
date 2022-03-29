#include "SortingAlgorithm.h"

SortingAlgorithm::SortingAlgorithm(std::vector<Element>& elems)
{
    this->elems = &elems;
    this->finished = false;
    this->stopping = false;
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

void SortingAlgorithm::stop()
{
    stopping = true;
}
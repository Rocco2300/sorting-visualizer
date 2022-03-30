#include "SortingAlgorithm.h"

SortingAlgorithm::SortingAlgorithm(std::vector<Element>& elems)
{
    this->elems = &elems;
    this->finished = true;
}

void SortingAlgorithm::sort()
{
    finished = false;
    _sort();
    finished = true;
}

bool SortingAlgorithm::isFinished()
{
    return finished;
}

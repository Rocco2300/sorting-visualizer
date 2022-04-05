#include "SortingAlgorithm.h"

SortingAlgorithm::SortingAlgorithm(std::vector<Element>& elems)
{
    this->elems = &elems;
    this->finished = true;
    this->delay = 10;
    this->descending = false;
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

void SortingAlgorithm::setDelay(int delay)
{
    this->delay = delay;
}

void SortingAlgorithm::setDescending(bool value)
{
    descending = value;
}

bool SortingAlgorithm::compare(int a, int b)
{
    if(descending)
        return a < b;
    else 
        return a > b;
}
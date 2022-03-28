#pragma once

#include "SortingAlgorithm.h"

class CountSort : public SortingAlgorithm
{
public:
    CountSort(std::vector<Element>& elems);
private:
    void _sort() override;
    int getMax();
};


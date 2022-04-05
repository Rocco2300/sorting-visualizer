#pragma once

#include "SortingAlgorithm.h"

class CountSort : public SortingAlgorithm
{
private:
    friend class RadixSort;
public:
    CountSort(std::vector<Element>& elems);
    int getMax();
private:
    void _sort() override;
};

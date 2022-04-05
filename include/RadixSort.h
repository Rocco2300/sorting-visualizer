#pragma once

#include "SortingAlgorithm.h"

class RadixSort : public SortingAlgorithm
{
private:
public:
    RadixSort(std::vector<Element>& elems);
    void _sort() override;
private:
    int getMax();
    void countSortAsc(int exp);
    void countSortDesc(int exp);
};

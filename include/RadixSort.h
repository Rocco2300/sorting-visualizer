#pragma once

#include "SortingAlgorithm.h"

class CountSort : public SortingAlgorithm
{
public:
    CountSort(std::vector<Element>& elems);
    int getMax();
    void countSort(int exp);
private:
    void _sort() override;
};

class RadixSort : public SortingAlgorithm
{
private:
    CountSort* countSort;
public:
    RadixSort(std::vector<Element>& elems);
    void _sort() override;
};

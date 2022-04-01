#pragma once

#include "SortingAlgorithm.h"

class CountSort : public SortingAlgorithm
{
public:
    CountSort(std::vector<Element>& elems);
    int getMax();
private:
    void _sort() override;
};

class RadixSort : public SortingAlgorithm
{
public:
    RadixSort(std::vector<Element>& elems);
    void _sort() override;
private:
    int getMax();
    void countSort(int exp);
};

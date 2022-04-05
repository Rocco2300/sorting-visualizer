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

#pragma once

#include "SortingAlgorithm.h"

class RadixSort : public SortingAlgorithm
{
private:
public:
    RadixSort();
    void _sort(ElementList& elems, bool desc) override;
private:
    int getMax(ElementList& elems);
    void countSortAsc(ElementList& elems, int exp);
    void countSortDesc(ElementList& elems, int exp);
};

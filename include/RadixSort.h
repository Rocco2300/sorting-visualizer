#pragma once

#include "SortingAlgorithm.h"

class RadixSortLSD : public SortingAlgorithm
{
public:
    RadixSortLSD();
    void _sort(ElementList& elems, bool desc) override;
private:
    int getMax(ElementList& elems);
    void countSortAsc(ElementList& elems, int exp);
    void countSortDesc(ElementList& elems, int exp);
};
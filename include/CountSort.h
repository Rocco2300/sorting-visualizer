#pragma once

#include "SortingAlgorithm.h"

class CountSort : public SortingAlgorithm
{
public:
    CountSort();
    int getMax(ElementList& elems);
private:
    void _sort(ElementList& elems, bool desc) override;
};

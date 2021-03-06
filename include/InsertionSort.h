#pragma once

#include "SortingAlgorithm.h"

class InsertionSort : public SortingAlgorithm
{
public:
    InsertionSort();
private:
    void _sort(ElementList& elems, bool desc) override;
};


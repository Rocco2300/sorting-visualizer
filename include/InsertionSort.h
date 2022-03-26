#pragma once

#include "SortingAlgorithm.h"

class InsertionSort : public SortingAlgorithm
{
public:
    InsertionSort(std::vector<Element>& elems);
private:
    void _sort() override;
};


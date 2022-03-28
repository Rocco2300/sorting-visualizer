#pragma once

#include "SortingAlgorithm.h"

class SelectionSort : public SortingAlgorithm
{
public:
    SelectionSort(std::vector<Element>& elems);
private:
    void _sort() override;
};

#pragma once

#include "SortingAlgorithm.h"

class BubbleSort : public SortingAlgorithm
{
public:
    BubbleSort(std::vector<Element>& elems);
    void _sort() override;
};


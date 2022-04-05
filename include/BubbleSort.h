#pragma once

#include "SortingAlgorithm.h"

class BubbleSort : public SortingAlgorithm
{
public:
    BubbleSort(std::vector<Element>& elems);
private:
    void _sort() override;
};


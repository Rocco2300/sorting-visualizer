#pragma once

#include "SortingAlgorithm.h"

class SelectionSort : public SortingAlgorithm
{
public:
    SelectionSort();
private:
    void _sort(ElementList& elems, bool desc) override;
};

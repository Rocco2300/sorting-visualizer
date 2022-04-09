#pragma once

#include "SortingAlgorithm.h"

class SelectionSort : public SortingAlgorithm
{
public:
    SelectionSort();
private:
    bool compare(int a, int b, bool desc);
    void _sort(ElementList& elems, bool desc) override;
};

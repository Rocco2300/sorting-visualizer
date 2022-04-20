#pragma once

#include "SortingAlgorithm.h"

class BubbleSort : public SortingAlgorithm
{
public:
    BubbleSort();
private:
    void _sort(ElementList& elems, bool desc) override;
    void bubbleSort(ElementList& elems, bool desc);
};


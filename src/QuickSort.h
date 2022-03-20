#pragma once

#include "SortingAlgorithm.h"

class QuickSort : public SortingAlgorithm
{
private:

public:
    QuickSort(std::vector<Element>& elems);
private:
    void _sort() override;
    void quickSort(int low, int high);
    int partition(int low, int high);
};

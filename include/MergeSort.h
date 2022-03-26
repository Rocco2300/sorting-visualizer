#pragma once

#include "SortingAlgorithm.h"

class MergeSort : public SortingAlgorithm
{
public:
    MergeSort(std::vector<Element>& elems);
private:
    void _sort() override;
    void merge(int low, int mid, int high);
    void mergeSort(int low, int high);
};

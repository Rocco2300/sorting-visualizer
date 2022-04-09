#pragma once

#include "SortingAlgorithm.h"

class MergeSort : public SortingAlgorithm
{
public:
    MergeSort();
private:
    bool compare(int a, int b, bool desc);
    void _sort(ElementList& elems, bool desc) override;
    void merge(ElementList& elems, int low, int mid, int high, bool desc);
    void mergeSort(ElementList& elems, int low, int high, bool desc);
};

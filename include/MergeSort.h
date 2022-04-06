#pragma once

#include "SortingAlgorithm.h"

class MergeSort : public SortingAlgorithm
{
public:
    MergeSort();
private:
    void _sort(ElementList& elems, bool desc) override;
    void merge(ElementList& elems, int low, int mid, int high);
    void mergeSort(ElementList& elems, int low, int high);
};

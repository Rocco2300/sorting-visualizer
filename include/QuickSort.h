#pragma once

#include "SortingAlgorithm.h"

class QuickSort : public SortingAlgorithm
{
public:
    QuickSort();
private:
    void _sort(ElementList& elems, bool desc) override;
    void quickSort(ElementList& elems, int low, int high);
    int lomutoPartition(ElementList& elems, int low, int high);
    // int hoarePartition(int low, int high);
};

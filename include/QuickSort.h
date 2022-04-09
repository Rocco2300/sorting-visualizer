#pragma once

#include "SortingAlgorithm.h"

class QuickSort : public SortingAlgorithm
{
public:
    QuickSort();
private:
    bool compare(int a, int b, bool desc);
    void _sort(ElementList& elems, bool desc) override;
    void quickSort(ElementList& elems, int low, int high, bool desc);
    int lomutoPartition(ElementList& elems, int low, int high, bool desc);
    // int hoarePartition(int low, int high);
};

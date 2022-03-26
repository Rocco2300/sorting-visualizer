#pragma once

#include "SortingAlgorithm.h"

class QuickSort : public SortingAlgorithm
{
public:
    QuickSort(std::vector<Element>& elems);
private:
    void _sort() override;
    void quickSort(int low, int high);
    int lomutoPartition(int low, int high);
    int hoarePartition(int low, int high);
};

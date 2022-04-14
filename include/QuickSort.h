#pragma once

#include "SortingAlgorithm.h"

class QuickSort : public SortingAlgorithm
{
public:
    QuickSort();
    int selectedPivotIndex;
    std::vector<Element*> selectedElements;
private:
    bool compare(int a, int b, bool desc);
    void selectElements(ElementList& elems, int low, int high);
    void unselectElements();
    void _sort(ElementList& elems, bool desc) override;
    void quickSort(ElementList& elems, int low, int high, bool desc);
    int lomutoPartition(ElementList& elems, int low, int high, bool desc);
    // int hoarePartition(int low, int high);
};

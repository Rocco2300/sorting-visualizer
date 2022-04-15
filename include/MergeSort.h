#pragma once

#include <mutex>
#include "SortingAlgorithm.h"

class MergeSort : public SortingAlgorithm
{
private:
    std::mutex mutex;
    std::vector<Element*> range;
public:
    MergeSort();
private:
    void selectRange(ElementList& elems, int low, int high);
    void unselectRange(ElementList& elems);

    bool compare(int a, int b, bool desc);
    void _sort(ElementList& elems, bool desc) override;
    void merge(ElementList& elems, int low, int mid, int high, bool desc);
    void mergeSort(ElementList& elems, int low, int high, bool desc);
};

#pragma once

#include <functional>
#include <map>

#include "BubbleSort.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "CountSort.h"
#include "RadixSort.h"

// Constant variables

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

enum Settings
{
    CurrentElem = 0,
    ElementNo,
    CurrentHeight,
    CurrentList,
    TotalListNo
};

extern const char* algorithmIndexes[7];
extern SortingAlgorithm* algorithmList[7];
// extern int settings[2][3];
extern std::map<int, std::function<std::pair<float, float> (int[])>> functions;
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

enum Params
{
    CurrentElem = 0,
    ElementNo,
    CurrentHeight,
    CurrentList,
    TotalListNo
};

enum Pattern
{
    Normal = 0,
    Diamond
};

enum Temp
{
    Height = 0, 
    Divide
};

namespace cv
{
extern const char* algorithmIndexes[7];
extern const char* patternIndexes[2];
extern SortingAlgorithm* algorithmList[7];
extern const int listNumberSettings[2];
extern const int temporary[2][2];
extern std::map<Pattern, std::function<std::pair<float, float> (int[])>> functions;
};
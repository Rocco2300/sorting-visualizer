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

#include "NormalPattern.h"
#include "DiamondPattern.h"

// Constant variables

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

namespace cv
{
extern const char* algorithmIndexes[7];
extern SortingAlgorithm* algorithmList[7];
extern const char* patternIndexes[3];
extern Pattern* patternList[3];
extern const int listNumberSettings[3];
extern const int temporary[3][2];
};
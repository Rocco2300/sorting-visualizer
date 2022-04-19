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
#include "PyramidPattern.h"
#include "DiamondPattern.h"
#include "StarPattern.h"

// Constant variables

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

const sf::Color RANGE_COLOR = sf::Color(219, 249, 184, 255);
const sf::Color SELECTED_COLOR = sf::Color(221, 45, 74, 255);
const sf::Color SCROLL_COLOR = sf::Color(244, 156, 187, 255);

namespace cv
{
extern const char* algorithmIndexes[7];
extern SortingAlgorithm* algorithmList[7];
extern const char* patternIndexes[4];
extern Pattern* patternList[4];
extern const int listNumberSettings[3];
extern const int temporary[3][2];
};
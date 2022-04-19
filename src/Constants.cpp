#include "Constants.h"

namespace cv
{
const char* algorithmIndexes[7] =
{
    "Bubble Sort",
    "Selection Sort",
    "Insertion Sort",
    "Merge Sort",
    "Quick Sort",
    "Count Sort",
    "Radix Sort LSD",
};

SortingAlgorithm* algorithmList[7] = 
{
    new BubbleSort(),
    new SelectionSort(),
    new InsertionSort(),
    new MergeSort(),
    new QuickSort(),
    new CountSort(),
    new RadixSortLSD()
};

const char* patternIndexes[4] = 
{
    "Normal",
    "Pyramid",
    "Diamond",
    "Star"
};

Pattern* patternList[4] =
{
    new NormalPattern(),
    new PyramidPattern(),
    new DiamondPattern(),
    new StarPattern()
};

const int listNumberSettings[3] = { 1, 2, 4 };

const int temporary[3][2] = 
{ 
    {
        WINDOW_HEIGHT - 200,
        1
    },
    {
        WINDOW_HEIGHT - 200,
        2
    },
    {
        (WINDOW_HEIGHT / 2) - 35,
        2
    }
};
};

//  float x = (WINDOW_WIDTH / (float)elems * i) / listNumber + list* WINDOW_WIDTH/listNumber;
//  float y = WINDOW_HEIGHT - (WINDOW_HEIGHT - height) + 70;

// Base
// float x = (WINDOW_WIDTH / (float)elems * i);
// float y = WINDOW_HEIGHT;
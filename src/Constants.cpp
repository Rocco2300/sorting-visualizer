#include "Constants.h"

namespace cv
{
const char* algorithmIndexes[5] =
{
    "Bubble Sort",
    "Selection Sort",
    "Insertion Sort",
    // "Merge Sort",
    "Quick Sort",
    "Count Sort"
    // "Radix Sort LSD"
};

SortingAlgorithm* algorithmList[5] = 
{
    new BubbleSort(),
    new SelectionSort(),
    new InsertionSort(),
    // new MergeSort(),
    new QuickSort(),
    new CountSort()
    // new RadixSortLSD()
};

const char* patternIndexes[1] = 
{
    "Normal",
    // "Pyramid",
    // "Diamond",
    // "Star"
};

Pattern* patternList[1] =
{
    new NormalPattern(),
    // new PyramidPattern(),
    // new DiamondPattern(),
    // new StarPattern()
};
};

//  float x = (WINDOW_WIDTH / (float)elems * i) / listNumber + list* WINDOW_WIDTH/listNumber;
//  float y = WINDOW_HEIGHT - (WINDOW_HEIGHT - height) + 70;

// Base
// float x = (WINDOW_WIDTH / (float)elems * i);
// float y = WINDOW_HEIGHT;
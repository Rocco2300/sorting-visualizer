#include "Constants.h"

// const char* algorithmIndexes[7];
// SortingAlgorithm algorithmList[7];

const char* algorithmIndexes[7] =
{
    "Bubble Sort",
    "Selection Sort",
    "Insertion Sort",
    "Merge Sort",
    "Quick Sort",
    "Count Sort",
    "Radix Sort"
};

const char* patternIndexes[2] = 
{
    "Normal",
    "Diamond"
};

SortingAlgorithm* algorithmList[7] = 
{
    new BubbleSort(),
    new SelectionSort(),
    new InsertionSort(),
    new MergeSort(),
    new QuickSort(),
    new CountSort(),
    new RadixSort()
};

const int listNumberSettings[2] = { 1, 4 };

const int heights[2] = { WINDOW_HEIGHT - 200, (WINDOW_HEIGHT / 2) - 35 };

std::map<Pattern, std::function<std::pair<float, float> (int[])>> functions
{
    {
        Pattern::Normal,
        [](int settings[])
        {
            int i = settings[CurrentElem];
            int elems = settings[ElementNo];

            float x = (WINDOW_WIDTH / (float)elems * i);
            float y = WINDOW_HEIGHT;

            return std::make_pair(x, y);
        }
    },
    {
        Pattern::Diamond,
        [](int settings[])
        {
            int i = settings[CurrentElem];
            int elems = settings[ElementNo];
            int height = settings[CurrentHeight];
            int list = settings[CurrentList];

            int offsetX = list % 2;
            int offsetY = list / 2;
            
            float x = (WINDOW_WIDTH / (float)elems * i) / 2 + offsetX * WINDOW_WIDTH / 2;
            float y = (offsetY == 0) ? (offsetY * WINDOW_HEIGHT / 2 + WINDOW_HEIGHT / 2) + 35
                                     : (WINDOW_HEIGHT - (WINDOW_HEIGHT - height)) + offsetY * WINDOW_HEIGHT / 2 + 35;

            return std::make_pair(x, y);
        }
    }
};

//  float x = (WINDOW_WIDTH / (float)elems * i) / listNumber + list* WINDOW_WIDTH/listNumber;
//  float y = WINDOW_HEIGHT - (WINDOW_HEIGHT - height) + 70;

// Base
// float x = (WINDOW_WIDTH / (float)elems * i);
// float y = WINDOW_HEIGHT;
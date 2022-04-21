#include "DiamondPattern.h"

#include <cmath>
#include <iostream>
#include "Constants.h"

DiamondPattern::DiamondPattern()
{
    this->listNumber = 4;
    this->elemLists = nullptr;
}

void DiamondPattern::initializeLists()
{
    elemLists->clear();
    elemLists->reserve(listNumber);

    for(int list = 0; list < listNumber; list++)
    {
        ElementList temp;

        int height = (WINDOW_HEIGHT / 2) - 35;
        for(int i = 0; i < elements; i++)
        {
            float w = (WINDOW_WIDTH / (float)elements) / 2;
            float h = height * ((i+1) / (float)elements);
            Element el(w, h);

            int offsetX = list % 2;
            int offsetY = list / 2;

            if(offsetY != 0)
                el.setOrigin(0, 0);

            float x = (WINDOW_WIDTH / (float)elements * i) / 2 + offsetX * WINDOW_WIDTH / 2;
            float y = (WINDOW_HEIGHT / 2) + 35;
            
            el.setPosition(x, y);

            temp.push_back(std::move(el));
        }

        elemLists->push_back(temp);
    }
}

bool DiamondPattern::isDescending(int i)
{
    return (i % 2 == 0) ? descending : !descending;
}

void DiamondPattern::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for(int list = 0; list < listNumber; list++)
    {
        for(int i = 0; i < elements; i++)
        {
            target.draw(elemLists->at(list)[i]);
        }
    }
}
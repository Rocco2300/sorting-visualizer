#include "DiamondPattern.h"

#include <cmath>
#include <iostream>
#include "Constants.h"

#if CEVA
DiamondPattern::DiamondPattern()
{
    this->listNumber = 4;
    this->elements = nullptr;
    this->elemLists = nullptr;
}

void DiamondPattern::initializeLists()
{
    elemLists->clear();
    elemLists->reserve(listNumber);

    for(int i = 0; i < listNumber; i++)
    {
        ElementList temp;

        int height = (WINDOW_HEIGHT / 2) - 35;
        for(int j = 0; j < *elements; j++)
        {
            Element el;
            el.height = height * ((j+1) / (float)*elements);
            el.color = sf::Color::White;
            temp.push_back(el);
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
        sf::RectangleShape temp;
        for(int i = 0; i < *elements; i++)
        {
            float height = elemLists->at(list)[i].height;
            temp.setSize({(WINDOW_WIDTH / (float)*elements) / 2, height});
            temp.setFillColor(elemLists->at(list)[i].color);
            temp.setOrigin({0, height});

            int offsetX = list % 2;
            int offsetY = list / 2;
            
            float x = (WINDOW_WIDTH / (float)*elements * i) / 2 + offsetX * WINDOW_WIDTH / 2;
            float y;
            if(!descending)
            {
                y = (offsetY == 0) ? (offsetY * WINDOW_HEIGHT / 2 + WINDOW_HEIGHT / 2) + 35
                                     : (WINDOW_HEIGHT - (WINDOW_HEIGHT - height)) + offsetY * WINDOW_HEIGHT / 2 + 35;
            }
            else
            {
                y = (offsetY == 0) ? (WINDOW_HEIGHT - (WINDOW_HEIGHT - height)) + offsetY * WINDOW_HEIGHT / 2 + 70
                                     : (offsetY * WINDOW_HEIGHT / 2 + WINDOW_HEIGHT / 2);
            }
            temp.setPosition(x, y);

            target.draw(temp);
        }
    }
}
#endif
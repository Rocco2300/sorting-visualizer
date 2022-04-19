#include "StarPattern.h"

#include "Constants.h"

StarPattern::StarPattern()
{
    this->listNumber = 8;
    this->elements = nullptr;
    this->elemLists = nullptr;

    cnt = 0;
    swapped = false;
}

bool StarPattern::isDescending(int i)
{
    return descending;
    
    if(cnt < 2)
    {
        if(swapped)
            return !descending;
        else 
            return descending;
    }
    else 
    {
        cnt = 1;
        swapped = !swapped;
        return !descending;
    }
}

void StarPattern::initializeLists()
{
    elemLists->clear();
    elemLists->reserve(listNumber);

    int minHeight = 100;
    int maxHeight = WINDOW_HEIGHT - 170;

    for(int i = 0; i < listNumber; i++)
    {
        ElementList temp;

        int height = (i % 4) % 3 == 0 ? minHeight : maxHeight;
        for(int j = 0; j < *elements; j++)
        {
            Element el;
            el.height = height == maxHeight ? height * ((j+1) / (float)*elements) + 100 
                                            : height * ((j+1) / (float)*elements);
            el.color = sf::Color::White;
            temp.push_back(el);
        }

        elemLists->push_back(temp);
    }
}

void StarPattern::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for(int list = 0; list < listNumber; list++)
    {
        sf::RectangleShape temp;

        int currentWidth = 0;
        for(int i = 0; i < *elements; i++)
        {
            int x = i % 4;
            int y = i / 4;
    
            int divisor = x % 3 == 0 ? 800/300 : 100;
            temp.setSize({(WINDOW_WIDTH / (float)*elements) / divisor, elemLists->at(list)[i].height});
            temp.setFillColor(elemLists->at(list)[i].color);
            temp.setOrigin({0, elemLists->at(list)[i].height});

            int width = x % 3 == 0 ? 300 : 100;
            int posX = (width / (float)*elements * i) + currentWidth;
            int posY = (WINDOW_HEIGHT / 2) * y + (WINDOW_HEIGHT / 2);
            temp.setPosition(posX, posY);
            currentWidth += width;

            target.draw(temp);
        }
    }
}
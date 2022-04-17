#include "NormalPattern.h"

#include "Constants.h"

#include <cmath>

NormalPattern::NormalPattern()
{
    this->listNumber = 1;
    this->elements = nullptr;
    this->elemLists = nullptr;
}

void NormalPattern::initializeLists()
{
    elemLists->clear();
    elemLists->reserve(listNumber);

    for(int i = 0; i < listNumber; i++)
    {
        ElementList temp;

        int height = WINDOW_HEIGHT - 200;
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

bool NormalPattern::isDescending(int i)
{
    return descending;
}

void NormalPattern::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for(int list = 0; list < listNumber; list++)
    {
        sf::RectangleShape temp;
        for(int i = 0; i < *elements; i++)
        {
            temp.setSize({(WINDOW_WIDTH / (float)*elements), elemLists->at(list)[i].height});
            temp.setFillColor(elemLists->at(list)[i].color);
            temp.setOrigin({0, elemLists->at(list)[i].height});
            temp.setPosition((WINDOW_WIDTH / (float)*elements * i), WINDOW_HEIGHT);

            target.draw(temp);
        }
    }
}
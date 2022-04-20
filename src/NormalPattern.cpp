#include "NormalPattern.h"

#include "Constants.h"

#include <iostream>

NormalPattern::NormalPattern()
{
    this->listNumber = 1;
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
        for(int j = 0; j < elements; j++)
        {
            float w = WINDOW_WIDTH / (float)elements;
            float h = height * ((j+1) / (float)elements);

            Element el(w, h);
            el.setFillColor(sf::Color::White);
            el.setOrigin(0.f, h);
            el.setPosition((WINDOW_WIDTH / (float)elements) * j, (float)WINDOW_HEIGHT);
            temp.push_back(std::move(el));
        }
        
        elemLists->push_back(std::move(temp));
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
        for(int i = 0; i < elements; i++)
        {
            target.draw(elemLists->at(list)[i], states);
        }
    }
}
#include "PyramidPattern.h"

#include "Constants.h"

PyramidPattern::PyramidPattern()
{
    this->listNumber = 2;
    this->elements = nullptr;
    this->elemLists = nullptr;
}

void PyramidPattern::initializeLists()
{
    elemLists->clear();
    elemLists->reserve(listNumber);

    for(int i = 0; i < listNumber; i++)
    {
        ElementList temp;

        int height = WINDOW_HEIGHT - 200;
        for(int i = 0; i < *elements; i++)
        {
            Element el;
            el.height = height * ((i+1) / (float)*elements);
            el.color = sf::Color::White;
            temp.push_back(el);
        }

        elemLists->push_back(temp);
    }
}

bool PyramidPattern::isDescending(int i)
{
    return (i % 2 == 0) ? descending : !descending;
}

void PyramidPattern::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for(int list = 0; list < listNumber; list++)
    {
        sf::RectangleShape temp;
        for(int i = 0; i < *elements; i++)
        {
            temp.setSize({(WINDOW_WIDTH / (float)*elements) / 2, elemLists->at(list)[i].height});
            temp.setFillColor(elemLists->at(list)[i].color);
            temp.setOrigin({0, elemLists->at(list)[i].height});
            temp.setPosition((WINDOW_WIDTH / (float)*elements * i) / 2 + list * WINDOW_WIDTH / 2, WINDOW_HEIGHT);

            target.draw(temp);
        }
    }
}
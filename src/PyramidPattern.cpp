#include "PyramidPattern.h"

#include "Constants.h"

PyramidPattern::PyramidPattern()
{
    this->listNumber = 2;
    this->elemLists = nullptr;
}

void PyramidPattern::initializeLists()
{
    elemLists->clear();
    elemLists->reserve(listNumber);

    for(int list = 0; list < listNumber; list++)
    {
        ElementList temp;

        int height = WINDOW_HEIGHT - 200;
        for(int i = 0; i < elements; i++)
        {
            float w = (WINDOW_WIDTH / (float)elements) / 2;
            float h = height * ((i+1) / (float)elements);
            Element el(w, h);

            el.setPosition((WINDOW_WIDTH / (float)elements * i) / 2 + list * (WINDOW_WIDTH / 2), WINDOW_HEIGHT);

            temp.push_back(std::move(el));
        }

        elemLists->push_back(std::move(temp));
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
        for(int i = 0; i < elements; i++)
        {
            target.draw(elemLists->at(list)[i]);
        }
    }
}
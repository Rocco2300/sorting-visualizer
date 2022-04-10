#include "NormalPattern.h"

#include "Constants.h"

NormalPattern::NormalPattern()
{
    this->listNumber = 1;
    this->elements = nullptr;
    this->elemLists = nullptr;
}

void NormalPattern::initializeLists(std::vector<ElementList>& elLists, int& elems, bool& desc)
{
    if(!elements)
        elements = &elems;
    
    if(!elemLists)
        elemLists = &elLists;

    if(!descending)
        descending = &desc;

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
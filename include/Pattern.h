#pragma once

#include <SFML/Graphics.hpp>

#include "Constants.h"

class Pattern : public sf::Drawable
{
protected:
    std::vector<ElementList>* elemLists;
    int* elements;
    int listNumber;
public:
    Pattern();
    virtual ~Pattern() {}
    virtual void initializeLists() = 0;
    void setElements(int& elemNo);
    int getListNumber();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};


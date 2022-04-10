#pragma once

#include <SFML/Graphics.hpp>

#include "SortingAlgorithm.h"

class Pattern : public sf::Drawable
{
protected:
    std::vector<ElementList>* elemLists;
    int* elements;
    bool* descending;
    int listNumber;
public:
    Pattern();
    virtual ~Pattern() {}
    virtual void initializeLists(std::vector<ElementList>& elLists, int& elems, bool& desc) = 0;
    int getListNumber();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};


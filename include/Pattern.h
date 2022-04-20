#pragma once

#include <SFML/Graphics.hpp>

#include "SortingAlgorithm.h"

class Pattern : public sf::Drawable
{
protected:
    std::vector<ElementList>* elemLists;
    int elements;
    bool descending;
    int listNumber;
public:
    Pattern();
    virtual ~Pattern() {}

    int getListNumber();
    
    void setPointer(std::vector<ElementList>& elLists);
    void setDescending(bool desc);
    void setElementNo(int elementNo);

    virtual void initializeLists() = 0;
    virtual bool isDescending(int i) = 0;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};  


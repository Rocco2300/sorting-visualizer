#pragma once

#include "Pattern.h"

class PyramidPattern : public Pattern
{
public:
    PyramidPattern();
    void initializeLists(std::vector<ElementList>& elLists, int& elems, bool& desc);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


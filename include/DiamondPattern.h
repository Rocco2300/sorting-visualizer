#pragma once

#include "Pattern.h"

class DiamondPattern : public Pattern
{
public:
    DiamondPattern();
    void initializeLists(std::vector<ElementList>& elLists, int& elems, bool& desc);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

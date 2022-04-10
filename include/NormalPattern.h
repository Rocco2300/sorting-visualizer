#pragma once

#include "Pattern.h"

class NormalPattern : public Pattern
{
public:
    NormalPattern();
    void initializeLists(std::vector<ElementList>& elLists, int& elems, bool& desc);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


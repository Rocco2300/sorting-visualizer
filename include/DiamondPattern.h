#pragma once

#include "Pattern.h"

class DiamondPattern : public Pattern
{
public:
    DiamondPattern();
    void initializeLists();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

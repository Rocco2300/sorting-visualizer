#pragma once

#include "Pattern.h"

class NormalPattern : public Pattern
{
public:
    NormalPattern();
    void initializeLists();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

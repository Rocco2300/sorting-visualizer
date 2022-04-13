#pragma once

#include "Pattern.h"

class NormalPattern : public Pattern
{
public:
    NormalPattern();
    void initializeLists();
    bool isDescending(int i);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


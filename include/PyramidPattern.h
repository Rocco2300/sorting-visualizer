#pragma once

#include "Pattern.h"

class PyramidPattern : public Pattern
{
public:
    PyramidPattern();
    void initializeLists();
    bool isDescending(int i);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


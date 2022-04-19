#pragma once

#include "Pattern.h"

class StarPattern : public Pattern
{
private:
    int cnt;
    bool swapped;
public:
    StarPattern();
    bool isDescending(int i) override;
    void initializeLists() override;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

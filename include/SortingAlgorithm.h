#pragma once

#include <SFML/Graphics.hpp>

struct Element
{
    float height;
    sf::Color color;
};

class SortingAlgorithm
{
private:
    std::vector<Element>* elems;
public:
    SortingAlgorithm(std::vector<Element>& elems);
    void sort();
};
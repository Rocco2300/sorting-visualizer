#pragma once

#include <SFML/Graphics.hpp>

class Element : public sf::Drawable
{
private:
    sf::RectangleShape* rect = nullptr;
public:
    Element();
    Element(float w, float h);
    Element(const Element& other);
    Element(Element&& other);
    ~Element();

    bool operator<(const Element& other) const;
    bool operator>(const Element& other) const;
    Element& operator=(const Element& other);
    
    sf::RectangleShape& operator()();

    static void swap(Element& a, Element& b);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

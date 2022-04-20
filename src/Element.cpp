#include "Element.h"

Element::Element()
{
    rect = new sf::RectangleShape({0, 0});
}

Element::Element(float w, float h)
{
    rect = new sf::RectangleShape({w, h});
    rect->setFillColor(sf::Color::White);
    rect->setOrigin(0, h);
    rect->setPosition(0, 0);
}

Element::Element(const Element& other)
{
    auto size = other.rect->getSize();
    rect = new sf::RectangleShape(size);

    auto pos = other.rect->getPosition();
    auto col = other.rect->getFillColor();

    rect->setPosition(pos);
    rect->setFillColor(col);
    rect->setOrigin(0, size.y);
}

Element::Element(Element&& other)
{
    delete rect;
    rect = other.rect;

    other.rect = nullptr;
}

Element::~Element()
{
    delete rect;
}

void Element::setFillColor(sf::Color color)
{
    rect->setFillColor(color);
}

bool Element::operator<(const Element& other) const
{
    return rect->getSize().y < other.rect->getSize().y;
}

bool Element::operator>(const Element& other) const
{
    return rect->getSize().y > other.rect->getSize().y;
}

Element& Element::operator=(const Element& other)
{
    auto size = other.rect->getSize();
    auto col = other.rect->getFillColor();

    rect->setSize(size);
    rect->setFillColor(col);
    rect->setOrigin(0, size.y);

    return *this;
}

void Element::swap(Element& a, Element& b)
{
    auto aux = a;
    a = b;
    b = aux;
}

void Element::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
    target.draw(*rect, states);
}
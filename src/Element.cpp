#include "Element.h"
#include <iostream>

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
    auto org = other.rect->getOrigin();

    rect->setPosition(pos);
    rect->setFillColor(col);
    rect->setOrigin(org);
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

int Element::getHeight()
{
    return (int)rect->getSize().y;
}

sf::Vector2f Element::getOrigin()
{
    return rect->getOrigin();
}

void Element::setOrigin(float x, float y)
{
    rect->setOrigin(x, y);
}

void Element::setPosition(float x, float y)
{
    rect->setPosition(x, y);
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
    auto org = other.rect->getOrigin();

    rect->setSize(size);
    rect->setFillColor(col);
    rect->setOrigin(org);

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
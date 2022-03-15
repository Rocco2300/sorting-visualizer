#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

const int WINDOW_WIDTH = 600;
const int WINDOW_HEIGHT = 400;

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");

    std::vector<sf::RectangleShape> rects;

    int rectNo = 100;
    for(int i = 0; i < rectNo; i++)
    {
        float height = (WINDOW_HEIGHT - 20) * ((i+1) / (float)rectNo);
        sf::RectangleShape temp({WINDOW_WIDTH / 20, height});
        temp.setFillColor(sf::Color::White);
        temp.setOutlineThickness(1);
        temp.setOutlineColor(sf::Color::Black);
        temp.setOrigin({WINDOW_WIDTH / (float)rectNo, height});
        temp.setPosition({WINDOW_WIDTH / (float)rectNo * i + WINDOW_WIDTH / rectNo, WINDOW_HEIGHT});
        rects.push_back(temp);
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for(int i = 0; i < rectNo; i++)
        {
            window.draw(rects[i]);
        }
        window.display();
    }

    return 0;
}
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <random>
#include <ctime>
#include <algorithm>

const int WINDOW_WIDTH = 600;
const int WINDOW_HEIGHT = 400;

void swapShapes(sf::RectangleShape* shape1, sf::RectangleShape* shape2)
{
    // auto width = shape1.getGlobalBounds().width;
    // auto height1 = shape1.getGlobalBounds().height;
    // auto height2 = shape2.getGlobalBounds().height;

    // auto origin1 = shape1.getOrigin();
    // auto origin2 = shape2.getOrigin();

    // auto pos1 = shape1.getPosition();
    // auto pos2 = shape2.getPosition();

    // shape1.setSize({width, height2});
    // shape1.setOrigin(origin2);
    // shape1.setPosition(pos2);

    // shape2.setSize({width, height1});
    // shape2.setOrigin(origin1);
    // shape2.setPosition(pos1);
    auto temp = shape1;
    shape1 = shape2;
    shape2 = temp;
}

void shuffle(std::vector<sf::RectangleShape> shapes)
{
    for(size_t i = shapes.size()-1; i >= 1; i--)
    {
        int j = rand() % i;
        std::swap(shapes[i], shapes[j]);
        // swapShapes(&shapes[i], &shapes[j]);
    }
}

int main()
{
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");

    std::vector<float> heights;

    int rectNo = 20;
    heights.reserve(rectNo);
    for(int i = 0; i < rectNo; i++)
    {
        float height = (WINDOW_HEIGHT - 20) * ((i+1) / (float)rectNo);
        heights.push_back(height);
    }
    // for(int i = 0; i < rectNo; i++)
    // {
    //     float height = (WINDOW_HEIGHT - 20) * ((i+1) / (float)rectNo);
    //     sf::RectangleShape temp({WINDOW_WIDTH / 20, height});
    //     temp.setFillColor(sf::Color::White);
    //     temp.setOrigin({WINDOW_WIDTH / (float)rectNo, height});
    //     temp.setPosition({WINDOW_WIDTH / (float)rectNo * i + WINDOW_WIDTH / rectNo, WINDOW_HEIGHT});
    //     rects.push_back(temp);
    // }

    std::random_shuffle(heights.begin(), heights.end());

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
            sf::RectangleShape temp({WINDOW_WIDTH / 20, heights[i]});
            temp.setFillColor(sf::Color::White);
            temp.setOrigin({WINDOW_WIDTH / (float)rectNo, heights[i]});
            temp.setPosition({WINDOW_WIDTH / (float)rectNo * i + WINDOW_WIDTH / rectNo, WINDOW_HEIGHT});
            window.draw(temp);
        }
        window.display();
    }

    return 0;
}
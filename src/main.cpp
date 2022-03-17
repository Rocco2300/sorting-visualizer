#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <random>
#include <ctime>
#include <algorithm>
#include <thread>

const int WINDOW_WIDTH = 600;
const int WINDOW_HEIGHT = 400;

struct Element
{
    float height;
    sf::Color color;
};

void bubbleSort(std::vector<Element>& vec)
{
    for(size_t i = 0; i < vec.size()-1; i++)
    {
        for(size_t j = 0; j < vec.size()-i-1; j++)
        {
            if(vec[j].height > vec[j+1].height)
            {
                vec[j].color = sf::Color::Red;
                std::swap(vec[j], vec[j+1]);
            }
            else
                vec[j].color = sf::Color::White;
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
        vec[vec.size()-i-1].color = sf::Color::White;
    }
}

int main()
{
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");

    std::vector<Element> elems;

    int rectNo = 20;
    elems.reserve(rectNo);
    for(int i = 0; i < rectNo; i++)
    {
        Element el;
        el.height = (WINDOW_HEIGHT - 20) * ((i+1) / (float)rectNo);
        el.color = sf::Color::White;
        elems.push_back(el);
    }

    std::random_shuffle(elems.begin(), elems.end());
    // bubbleSort(heights);
    std::thread th(bubbleSort, std::ref(elems));

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
            sf::RectangleShape temp({WINDOW_WIDTH / 20, elems[i].height});
            temp.setFillColor(elems[i].color);
            temp.setOrigin({WINDOW_WIDTH / (float)rectNo, elems[i].height});
            temp.setPosition({WINDOW_WIDTH / (float)rectNo * i + WINDOW_WIDTH / rectNo, WINDOW_HEIGHT});
            window.draw(temp);
        }
        window.display();
    }
    th.join();
    return 0;
}
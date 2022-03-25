#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <random>
#include <ctime>
#include <algorithm>
#include "BubbleSort.h"
#include "QuickSort.h"

const int WINDOW_WIDTH = 600;
const int WINDOW_HEIGHT = 400;

int main()
{
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");
    window.setFramerateLimit(60);

    std::vector<Element> elems;

    int rectNo = 10;
    elems.reserve(rectNo);
    for(int i = 0; i < rectNo; i++)
    {
        Element el;
        el.height = (WINDOW_HEIGHT - 20) * ((i+1) / (float)rectNo);
        el.color = sf::Color::White;
        elems.push_back(el);
    }

    SortingAlgorithm* sorting = new QuickSort(elems);
    std::random_shuffle(elems.begin(), elems.end());
    // bubbleSort(heights);
    std::thread thread(&SortingAlgorithm::sort, sorting);
    // sorting->sort();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                if(thread.joinable())
                    thread.detach();
            }
        }

        window.clear();
        for(int i = 0; i < rectNo; i++)
        {
            sf::RectangleShape temp({WINDOW_WIDTH / (float)rectNo, elems[i].height});
            temp.setFillColor(elems[i].color);
            temp.setOrigin({WINDOW_WIDTH / (float)rectNo, elems[i].height});
            temp.setPosition({WINDOW_WIDTH / (float)rectNo * i + WINDOW_WIDTH / rectNo, WINDOW_HEIGHT});
            window.draw(temp);
        }
        window.display();

        if(sorting->isFinished() && thread.joinable())
        {
            thread.join();
            std::cout << "Done" << std::endl;
        }
    }
    return 0;
}
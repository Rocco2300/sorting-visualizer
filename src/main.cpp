#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <random>
#include <ctime>
#include <algorithm>
#include <thread>

const int WINDOW_WIDTH = 600;
const int WINDOW_HEIGHT = 400;

void bubbleSort(std::vector<float>& vec)
{
    for(size_t i = 0; i < vec.size()-1; i++)
    {
        for(size_t j = 0; j < vec.size()-i-1; j++)
        {
            if(vec[j] > vec[j+1])
            {
                std::swap(vec[j], vec[j+1]);
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(30));
        }
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

    std::random_shuffle(heights.begin(), heights.end());
    // bubbleSort(heights);
    std::thread th(bubbleSort, std::ref(heights));

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
    th.join();
    return 0;
}
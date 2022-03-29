#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <random>
#include <ctime>
#include <algorithm>
#include "BubbleSort.h"
#include "imgui.h"
#include "imgui-SFML.h"
// #include "QuickSort.h"
// #include "MergeSort.h"
// #include "InsertionSort.h"
// #include "SelectionSort.h"
// #include "CountSort.h"

const int WINDOW_WIDTH = 600;
const int WINDOW_HEIGHT = 400;

int main()
{
    sf::Clock clock;
    sf::Time dt;

    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);

    std::vector<Element> elems;

    int rectNo = 50;
    elems.reserve(rectNo);
    for(int i = 0; i < rectNo; i++)
    {
        Element el;
        el.height = (WINDOW_HEIGHT - 20) * ((i+1) / (float)rectNo);
        el.color = sf::Color::White;
        elems.push_back(el);
    }

    std::thread thread;
    SortingAlgorithm* sorting = new BubbleSort(elems);
    std::random_shuffle(elems.begin(), elems.end());

    while (window.isOpen())
    {   
        dt = clock.restart();

        sf::Event event;
        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(window, event);

            if (event.type == sf::Event::Closed)
            {
                window.close();
                if(thread.joinable())
                    thread.detach();
            }
        }

        ImGui::SFML::Update(window, dt);

        ImGui::Begin("Hello, World!", NULL, ImGuiWindowFlags_NoTitleBar 
                                            | ImGuiWindowFlags_NoMove
                                            | ImGuiWindowFlags_NoResize);
        if(ImGui::Button("Start") && !thread.joinable())
        {
            thread = std::thread(&SortingAlgorithm::sort, sorting);
        }
        ImGui::SameLine();
        if(ImGui::Button("Pause") && thread.joinable())
        {
            sorting->stop();
            thread = std::thread();
        }
        ImGui::End();

        window.clear();
        for(int i = 0; i < rectNo; i++)
        {
            sf::RectangleShape temp({WINDOW_WIDTH / (float)rectNo, elems[i].height});
            temp.setFillColor(elems[i].color);
            temp.setOrigin({WINDOW_WIDTH / (float)rectNo, elems[i].height});
            temp.setPosition({WINDOW_WIDTH / (float)rectNo * i + WINDOW_WIDTH / rectNo, WINDOW_HEIGHT});
            window.draw(temp);
        }
        ImGui::SFML::Render(window);
        window.display();

        if(sorting->isFinished() && thread.joinable())
        {
            thread.join();
            std::cout << "Done" << std::endl;
        }
    }
    ImGui::SFML::Shutdown();
    return 0;
}
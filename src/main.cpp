#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <random>
#include <ctime>
#include <algorithm>
#include "imgui.h"
#include "imgui-SFML.h"
#include "BubbleSort.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "CountSort.h"


const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

void initializeList(std::vector<Element>& elems, int rectNo)
{
    elems.reserve(rectNo);
    int height = WINDOW_HEIGHT - 200;
    for(int i = 0; i < rectNo; i++)
    {
        Element el;
        el.height = (height - 20) * ((i+1) / (float)rectNo);
        el.color = sf::Color::White;
        elems.push_back(el);
    }
}

int main()
{
    sf::Clock clock;
    sf::Time dt;

    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!", sf::Style::Close);
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);

    std::vector<Element> elems;

    int rectNo = 300;
    initializeList(elems, rectNo);
    // elems.reserve(rectNo);
    // int height = WINDOW_HEIGHT - 200;
    // for(int i = 0; i < rectNo; i++)
    // {
    //     Element el;
    //     el.height = (height - 20) * ((i+1) / (float)rectNo);
    //     el.color = sf::Color::White;
    //     elems.push_back(el);
    // }
    std::random_shuffle(elems.begin(), elems.end());

    std::thread thread;
    SortingAlgorithm* sorting = new MergeSort(elems);

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
        if(ImGui::SliderInt("Element No.", &rectNo, 50, 800))
        {
            initializeList(elems, rectNo);
            std::random_shuffle(elems.begin(), elems.end());
        }
        ImGui::End();

        window.clear();
        for(int i = 0; i < rectNo; i++)
        {
            sf::RectangleShape temp({WINDOW_WIDTH / (float)rectNo, elems[i].height});
            temp.setFillColor(elems[i].color);
            temp.setOrigin({0, elems[i].height});
            temp.setPosition({WINDOW_WIDTH / (float)rectNo * i, WINDOW_HEIGHT});
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
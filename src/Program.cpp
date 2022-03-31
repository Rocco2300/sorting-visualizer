#include "Program.h"

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

Program::Program()
{
    srand(time(NULL));
    window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!", sf::Style::Close);
    window.setFramerateLimit(60);
    
    if(!ImGui::SFML::Init(window))
        std::cerr << "Error opening imgui window!\n";

    delay = 5;
    elementNo = 1000;
    initializeList();
    std::random_shuffle(elements.begin(), elements.end());

    sortingAlgorithm = new QuickSort(elements);
    sortingAlgorithm->setDelay(delay);
}

void Program::initializeList()
{
    elements.clear();
    elements.reserve(elementNo);
    int height = WINDOW_HEIGHT - 200;
    for(int i = 0; i < elementNo; i++)
    {
        Element el;
        el.height = (height - 20) * ((i+1) / (float)elementNo);
        el.color = sf::Color::White;
        elements.push_back(el);
    }
}

void Program::update()
{
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

        if(ImGui::Button("Start", {60, 30}) && !thread.joinable())
        {
            thread = std::thread(&SortingAlgorithm::sort, sortingAlgorithm);
        }
        ImGui::PushItemWidth(200);
        if(ImGui::SliderInt("Element No.", &elementNo, 50, 2048))
        {
            initializeList();
            std::random_shuffle(elements.begin(), elements.end());
        }
        ImGui::SameLine(0.f, 10.f);
        if(ImGui::SliderInt("Delay", &delay, 1, 125))
        {
            sortingAlgorithm->setDelay(delay);
        }
        ImGui::PopItemWidth();
        ImGui::End();

        window.clear();
        for(int i = 0; i < elementNo; i++)
        {
            sf::RectangleShape temp({WINDOW_WIDTH / (float)elementNo, elements[i].height});
            temp.setFillColor(elements[i].color);
            temp.setOrigin({0, elements[i].height});
            temp.setPosition({WINDOW_WIDTH / (float)elementNo * i, WINDOW_HEIGHT});
            window.draw(temp);
        }
        ImGui::SFML::Render(window);
        window.display();

        if(sortingAlgorithm->isFinished() && thread.joinable())
        {
            thread.join();
            std::cout << "Done" << std::endl;
        }
    }
    ImGui::SFML::Shutdown();
}
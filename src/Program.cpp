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
#include "RadixSort.h"

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
    shuffled = true;
    descending = false;

    currentItem = 0;
    buildAlgorithmList();
    // sortingAlgorithm = algorithmList[currentItem];
    sortingAlgorithm = new BubbleSort(elements);
    sortingAlgorithm->setDelay(delay);
}

Program::~Program()
{
    destroyAlgorithmList();
}

void Program::buildAlgorithmList()
{
    algorithmIndexes[0] = "Bubble Sort";
    algorithmIndexes[1] = "Selection Sort";
    algorithmIndexes[2] = "Insertion Sort";
    algorithmIndexes[3] = "Merge Sort";
    algorithmIndexes[4] = "Quick Sort";
    algorithmIndexes[5] = "Count Sort";
    algorithmIndexes[6] = "Radix Sort";
    algorithmList[0] = new BubbleSort(elements);
    algorithmList[1] = new SelectionSort(elements);
    algorithmList[2] = new InsertionSort(elements);
    algorithmList[3] = new MergeSort(elements);
    algorithmList[4] = new QuickSort(elements);
    algorithmList[5] = new CountSort(elements);
    algorithmList[6] = new RadixSort(elements);
}

void Program::destroyAlgorithmList()
{
    for(int i = 0; i < 6; i++)
    {
        delete algorithmList[i];
    }
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

        if(ImGui::Button("Start", {60, 20}) && !thread.joinable())
        {
            if(!shuffled)
            {
                std::random_shuffle(elements.begin(), elements.end());
                shuffled = true;
            }
            thread = std::thread(&SortingAlgorithm::sort, sortingAlgorithm);
        }
        ImGui::SameLine(0.f, 10.f);
        if(ImGui::Button("Shuffle", {60, 20}) && !thread.joinable())
        {
            shuffled = true;
            std::random_shuffle(elements.begin(), elements.end());
        }
        ImGui::SameLine(0.f, 10.f);
        if(ImGui::Checkbox("Descending", &descending))
        {
            actions.push(Action::Descending);
        }
        ImGui::SameLine(500.f, 0.f);
        ImGui::PushItemWidth(200);
        if(ImGui::Combo("Algorithm", &currentItem, algorithmIndexes, 7))
        {
            actions.push(Action::AlgorithmChange);
        }
        ImGui::Spacing();
        if(ImGui::SliderInt("Element No.", &elementNo, 50, 2048))
        {
            actions.push(Action::Resize);
        }
        ImGui::SameLine(0.f, 10.f);
        ImGui::PushItemWidth(150);
        if(ImGui::SliderInt("Delay", &delay, 1, 125))
        {
            sortingAlgorithm->setDelay(delay);
        }
        ImGui::PopItemWidth();
        ImGui::End();

        window.clear();
        for(size_t i = 0; i < elements.size(); i++)
        {
            int elems = elements.size();
            sf::RectangleShape temp({WINDOW_WIDTH / (float)elems, elements[i].height});
            temp.setFillColor(elements[i].color);
            temp.setOrigin({0, elements[i].height});
            temp.setPosition({WINDOW_WIDTH / (float)elems * i, WINDOW_HEIGHT});
            window.draw(temp);
        }
        ImGui::SFML::Render(window);
        window.display();

        if(sortingAlgorithm->isFinished() && thread.joinable())
        {
            thread.join();
            shuffled = false;
            std::cout << "Done" << std::endl;
        }
        
        if(!thread.joinable())
            performActions();
    }
    ImGui::SFML::Shutdown();
}

void Program::performActions()
{
    Action action;
    while(!actions.empty())
    {
        action = actions.top();
        actions.pop();

        switch(action)
        {
        case Resize:
            initializeList();
            std::random_shuffle(elements.begin(), elements.end());
            break;
        case AlgorithmChange:
            sortingAlgorithm = algorithmList[currentItem];
            break;
        case Descending:
            sortingAlgorithm->setDescending(descending);
            break;
        }
    }
}
#include "Program.h"

#include <iostream>
#include <random>
#include <ctime>
#include <algorithm>

#include "imgui.h"
#include "imgui-SFML.h"

#include <SFML/Window.hpp>

Program::Program()
{
    srand(time(NULL));
    window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Sorting Visualizer", sf::Style::Close);
    window.setFramerateLimit(60);
    
    if(!ImGui::SFML::Init(window))
        std::cerr << "Error opening imgui window!\n";

    delay = 5;
    elementNo = 50;
    currentPattern = 0;
    shuffled = true;
    descending = false;

    pattern = cv::patternList[currentPattern];
    listNumber = pattern->getListNumber();
    pattern->setPointer(elemLists);
    pattern->setElementNo(elementNo);
    pattern->setDescending(descending);
    pattern->initializeLists();

    fpsTime = fpsClock.restart();

    currentAlgorithm = 0;
    sortingAlgorithm = cv::algorithmList[currentAlgorithm];
    sortingAlgorithm->setDelay(delay); 

    shuffleLists(0);
}

void Program::checkThreadProgress()
{
    for(int i = threadPool.size()-1; i >= 0; i--)
    {
        if(futures[i].wait_for(std::chrono::seconds(0)) == std::future_status::ready)
        {
            threadPool[i].join();
            threadPool.erase(threadPool.begin() + i);
            futures.erase(futures.begin() + i);
        }
    }
}

void Program::sortInitializer(std::promise<void>&& promise, int i, bool desc)
{
    sortingAlgorithm->sort(elemLists[i], desc);
    promise.set_value();
}

void Program::shuffleInitializer(std::promise<void>&& promise, int i, int delay)
{
    sortingAlgorithm->shuffle(elemLists[i], delay);
    promise.set_value();
}

void Program::shuffleLists(int delay)
{
    for(int i = 0; i < listNumber; i++)
    {
        std::promise<void> promise;
        std::future<void> future = promise.get_future();
        std::thread thread(&Program::shuffleInitializer, this, std::move(promise), i, delay);

        threadPool.push_back(std::move(thread));
        futures.push_back(std::move(future));
    }
    shuffled = true;
}

void Program::handleEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        ImGui::SFML::ProcessEvent(window, event);

        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
    }
}

void Program::update()
{
    while (window.isOpen())
    {   
        dt = clock.restart();
        handleEvents();

        ImGui::SFML::Update(window, dt);

        ImGui::Begin("Hello, World!", NULL, ImGuiWindowFlags_NoTitleBar 
                                            | ImGuiWindowFlags_NoMove
                                            | ImGuiWindowFlags_NoResize);

        if(ImGui::Button("Start", {60, 20}) && threadPool.empty())
        {
            pattern->setDescending(descending);

            if(!shuffled)
            {
                shuffleLists(0);
            }

            for(int i = 0; i < listNumber; i++)
            {
                std::promise<void> promise;
                std::future<void> future = promise.get_future();
                std::thread thread(&Program::sortInitializer, this, std::move(promise), i, pattern->isDescending(i));

                threadPool.push_back(std::move(thread));
                futures.push_back(std::move(future));
            }
            shuffled = false;
        }

        ImGui::SameLine(0.f, 10.f);
        if(ImGui::Button("Shuffle", {60, 20}) && threadPool.empty())
        {
            shuffleLists(delay);
        }
        ImGui::SameLine(0.f, 10.f);
        ImGui::Checkbox("Descending", &descending);
        ImGui::SameLine(500.f, 0.f);
        ImGui::PushItemWidth(200);
        int algoSize = sizeof(cv::algorithmIndexes) / sizeof(cv::algorithmIndexes[0]);
        if(ImGui::Combo("Algorithm", &currentAlgorithm, cv::algorithmIndexes, algoSize))
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
        ImGui::SameLine(0.f, 10.f);
        ImGui::PushItemWidth(200);
        int pattSize = sizeof(cv::patternIndexes) / sizeof(cv::patternIndexes[0]);
        if(ImGui::Combo("Pattern", &currentPattern, cv::patternIndexes, pattSize))
        {
            actions.push(Action::PatternChange);
        }
        ImGui::PopItemWidth();
        ImGui::End();

        draw();

        checkThreadProgress();        
        if(threadPool.empty())
            performActions();
    }
    ImGui::SFML::Shutdown();
}

void Program::draw()
{
    window.clear();

    window.draw(*pattern);
    ImGui::SFML::Render(window);

    window.display();
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
            pattern->setDescending(descending);
            pattern->setElementNo(elementNo);
            pattern->initializeLists();

            shuffleLists(0);
            break;
        case AlgorithmChange:
            sortingAlgorithm = cv::algorithmList[currentAlgorithm];
            break;
        case PatternChange:
            pattern = cv::patternList[currentPattern];
            listNumber = pattern->getListNumber();

            pattern->setPointer(elemLists);
            pattern->setElementNo(elementNo);
            pattern->setDescending(descending);
            pattern->initializeLists();

            shuffleLists(0);  
            break;
        }
    }
}
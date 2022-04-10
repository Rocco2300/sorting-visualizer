#include "Program.h"

#include <iostream>
#include <random>
#include <ctime>
#include <algorithm>

#include "imgui.h"
#include "imgui-SFML.h"

Program::Program()
{
    srand(time(NULL));
    window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Sorting Visualizer", sf::Style::Close);
    window.setFramerateLimit(60);
    
    if(!ImGui::SFML::Init(window))
        std::cerr << "Error opening imgui window!\n";

    delay = 5;
    elementNo = 1000;
    currentPattern = 0;

    pattern = new NormalPattern(elemLists);
    pattern->setElements(elementNo);
    listNumber = pattern->getListNumber();
    pattern->initializeLists();

    fpsTime = fpsClock.restart();

    for(int i = 0; i < listNumber; i++)
    {
        std::random_shuffle(elemLists[i].begin(), elemLists[i].end());
    }
    shuffled = true;
    descending = false;

    currentAlgorithm = 0;
    sortingAlgorithm = cv::algorithmList[currentAlgorithm];
    sortingAlgorithm->setDelay(delay);
}

Program::~Program()
{
    destroyAlgorithmList(cv::algorithmList);
}

void Program::destroyAlgorithmList(SortingAlgorithm* algoList[])
{
    for(int i = 0; i < 7; i++)
    {
        delete algoList[i];
    }
}

// void Program::initializeList(ElementList& elems)
// {
//     elems.clear();
//     elems.reserve(elementNo);

//     height = cv::temporary[pattern][Height];
//     for(int i = 0; i < elementNo; i++)
//     {
//         Element el;
//         el.height = height * ((i+1) / (float)elementNo);
//         el.color = sf::Color::White;
//         elems.push_back(el);
//     }
// }

// void Program::initializeLists(int no)
// {
//     elemLists.clear();
//     elemLists.reserve(no);
//     for(int i = 0; i < no; i++)
//     {
//         initializeList(elemLists[i]);
//     }
// }

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

void Program::initializer(std::promise<void>&& promise, int i, bool desc)
{
    sortingAlgorithm->sort(elemLists[i], desc);
    promise.set_value();
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

        fpsTime = fpsClock.getElapsedTime();
        if(fpsTime.asSeconds() >= 2.f)
        {
            fpsTime = fpsClock.restart();
            std::cout << 1.f/dt.asSeconds() << std::endl;
        }

        ImGui::SFML::Update(window, dt);

        ImGui::Begin("Hello, World!", NULL, ImGuiWindowFlags_NoTitleBar 
                                            | ImGuiWindowFlags_NoMove
                                            | ImGuiWindowFlags_NoResize);

        if(ImGui::Button("Start", {60, 20}) && threadPool.empty())
        {
            if(!shuffled)
            {
                for(int i = 0; i < listNumber; i++)
                {
                    std::random_shuffle(elemLists[i].begin(), elemLists[i].end());
                }
                shuffled = true;
            }

            for(int i = 0; i < listNumber; i++)
            {
                bool temp = (i % 2 == 0) ? descending : !descending;

                std::promise<void> promise;
                std::future<void> future = promise.get_future();
                std::thread thread(&Program::initializer, this, std::move(promise), i, temp);

                threadPool.push_back(std::move(thread));
                futures.push_back(std::move(future));
            }
            shuffled = false;
        }

        ImGui::SameLine(0.f, 10.f);
        if(ImGui::Button("Shuffle", {60, 20}) && threadPool.empty())
        {
            shuffled = true;
            for(int i = 0; i < listNumber; i++)
            {
                std::random_shuffle(elemLists[i].begin(), elemLists[i].end());
            }
        }
        ImGui::SameLine(0.f, 10.f);
        ImGui::Checkbox("Descending", &descending);
        ImGui::SameLine(500.f, 0.f);
        ImGui::PushItemWidth(200);
        if(ImGui::Combo("Algorithm", &currentAlgorithm, cv::algorithmIndexes, 7))
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
        if(ImGui::Combo("Pattern", &currentPattern, cv::patternIndexes, 3))
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
            pattern->setElements(elementNo);
            pattern->initializeLists();
            for(int i = 0; i < listNumber; i++)
            {
                std::random_shuffle(elemLists[i].begin(), elemLists[i].end());
            }
            break;
        case AlgorithmChange:
            sortingAlgorithm = cv::algorithmList[currentAlgorithm];
            break;
        // case PatternChange:

        //     listNumber = cv::listNumberSettings[pattern];
        //     height = cv::temporary[pattern][Height];
        //     initializeLists(listNumber);
        //     for(int i = 0; i < listNumber; i++)
        //     {
        //         std::random_shuffle(elemLists[i].begin(), elemLists[i].end());
        //     }
        //     break;
        }
    }
}
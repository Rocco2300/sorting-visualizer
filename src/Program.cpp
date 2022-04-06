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
#include "RadixSort.h"

Program::Program()
{
    srand(time(NULL));
    window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Sorting Visualizer", sf::Style::Close);
    window.setFramerateLimit(60);
    
    if(!ImGui::SFML::Init(window))
        std::cerr << "Error opening imgui window!\n";

    delay = 5;
    elementNo = 1000;
    listNumber = 2;
    for(int i = 0; i < 4; i++)
    {
        ElementList temp;
        elemLists.push_back(temp);
    }

    initializeLists(elemLists, listNumber);
    for(int i = 0; i < listNumber; i++)
    {
        std::random_shuffle(elemLists[i].begin(), elemLists[i].end());
    }
    shuffled = true;
    descending = false;

    currentItem = 0;
    buildAlgorithmList();
    // sortingAlgorithm = algorithmList[currentItem];
    sortingAlgorithm = algorithmList[currentItem];
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
    algorithmList[0] = new BubbleSort();
    algorithmList[1] = new SelectionSort();
    algorithmList[2] = new InsertionSort();
    algorithmList[3] = new MergeSort();
    algorithmList[4] = new QuickSort();
    algorithmList[5] = new CountSort();
    algorithmList[6] = new RadixSort();
}

void Program::destroyAlgorithmList()
{
    for(int i = 0; i < 7; i++)
    {
        delete algorithmList[i];
    }
}

void Program::initializeList(ElementList& elems)
{
    elems.clear();
    elems.reserve(elementNo);
    int height = WINDOW_HEIGHT - 200;
    for(int i = 0; i < elementNo; i++)
    {
        Element el;
        el.height = (height - 20) * ((i+1) / (float)elementNo);
        el.color = sf::Color::White;
        elems.push_back(el);
    }
}

void Program::initializeLists(std::vector<ElementList>& elemLists, int no)
{
    for(int i = 0; i < no; i++)
    {
        initializeList(elemLists[i]);
    }
}

void Program::checkThreadProgress()
{
    for(int i = threadPool.size()-1; i >= 0; i--)
    {
        if(futures[i].wait_for(std::chrono::seconds(0)) == std::future_status::ready)
        {
            int ret = futures[i].get();
            if(ret)
            {
                threadPool[i].join();
                threadPool.erase(threadPool.begin() + i);
                futures.erase(futures.begin() + i);
            }
        }
    }
}

void Program::initializer(std::promise<bool>&& promise, int i, bool desc)
{
    bool ret = sortingAlgorithm->sort(elemLists[i], desc);
    promise.set_value(ret);
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
        handleEvents();

        ImGui::SFML::Update(window, clock.restart());

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

                std::promise<bool> promise;
                std::future<bool> future = promise.get_future();
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

    for(int list = 0; list < listNumber; list++)
    {
        for(size_t i = 0; i < elemLists[0].size(); i++)
        {
            int elems = elemLists[list].size();
            sf::RectangleShape temp({(WINDOW_WIDTH / (float)elems) / listNumber, elemLists[list][i].height});
            temp.setFillColor(elemLists[list][i].color);
            temp.setOrigin({0, elemLists[list][i].height});
            temp.setPosition({(WINDOW_WIDTH / (float)elems * i) / listNumber + list* WINDOW_WIDTH/listNumber, WINDOW_HEIGHT});
            window.draw(temp);
        }
    }
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
            initializeLists(elemLists, listNumber);
            for(int i = 0; i < listNumber; i++)
            {
                std::random_shuffle(elemLists[i].begin(), elemLists[i].end());
            }
            break;
        case AlgorithmChange:
            sortingAlgorithm = algorithmList[currentItem];
            break;
        }
    }
}
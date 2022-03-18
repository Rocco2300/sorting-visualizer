#include "SortingAlgorithm.h"

#include <thread>

SortingAlgorithm::SortingAlgorithm(std::vector<Element>& elems)
{
    this->elems = &elems;
}

void SortingAlgorithm::sort()
{
    for(size_t i = 0; i < elems->size()-1; i++)
    {
        for(size_t j = 0; j < elems->size()-i-1; j++)
        {
            if(elems->at(j).height > elems->at(j+1).height)
            {
                elems->at(j).color = sf::Color::Red;
                std::swap(elems->at(j), elems->at(j+1));
            }
            else
                elems->at(j).color = sf::Color::White;
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
        elems->at(elems->size()-i-1).color = sf::Color::White;
    }
}
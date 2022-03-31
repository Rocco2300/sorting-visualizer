#include <SFML/Graphics.hpp>
#include "SortingAlgorithm.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

class Program
{
private:
    sf::RenderWindow window;

    sf::Clock clock;
    sf::Time dt;

    int delay;
    int elementNo;
    std::vector<Element> elements;
    std::thread thread;
    SortingAlgorithm* sortingAlgorithm;
public:
    Program();
    void update();
private:
    void initializeList();
};

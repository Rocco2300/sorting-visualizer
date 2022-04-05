#include <SFML/Graphics.hpp>
#include <string>
#include <stack>
#include "SortingAlgorithm.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

enum Action
{
    Resize,
    AlgorithmChange,
    Descending
};

class Program
{
private:
    sf::RenderWindow window;
    sf::Clock clock;

    std::thread thread;
    std::vector<Element> elements;
    std::stack<Action> actions;

    const char* algorithmIndexes[7];
    SortingAlgorithm* sortingAlgorithm;
    SortingAlgorithm* algorithmList[7];
    
    int delay;
    int elementNo;
    int currentItem;
    bool shuffled;
    bool descending;
public:
    Program();
    ~Program();
    void buildAlgorithmList();
    void destroyAlgorithmList();
    void update();
    void performActions();
private:
    void initializeList();
    void handleEvents();
    void draw();
};

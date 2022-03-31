#include <SFML/Graphics.hpp>
#include <string>
#include <stack>
#include "SortingAlgorithm.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

enum Action
{
    Resize,
    AlgorithmChange
};

class Program
{
private:
    sf::RenderWindow window;
    sf::Clock clock;
    sf::Time dt;

    std::thread thread;
    std::vector<Element> elements;
    std::stack<Action> actions;

    const char* algorithmIndexes[6];
    SortingAlgorithm* sortingAlgorithm;
    SortingAlgorithm* algorithmList[6];
    
    int delay;
    int elementNo;
    int currentItem;
    bool shuffled;
public:
    Program();
    ~Program();
    void buildAlgorithmList();
    void destroyAlgorithmList();
    void update();
    void performActions();
private:
    void initializeList();
};

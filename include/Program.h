#include <SFML/Graphics.hpp>
#include <string>
#include <stack>
#include <future>

#include "Constants.h"

enum Action
{
    Resize,
    AlgorithmChange,
    PatternChange
};

class Program
{
private:
    sf::RenderWindow window;
    sf::Clock clock;
    sf::Time dt;
    sf::Clock fpsClock;
    sf::Time fpsTime;

    std::vector<std::thread> threadPool;
    std::vector<std::future<void>> futures;
    std::vector<ElementList> elemLists;
    std::stack<Action> actions;

    SortingAlgorithm* sortingAlgorithm;
    Pattern* pattern;
    
    int currentAlgorithm;
    int currentPattern;
    int height;

    int delay;
    int elementNo;
    int listNumber;
    bool shuffled;
    bool descending;
public:
    Program();
    void update();
private:
    void sortInitializer(std::promise<void>&& promise, int i, bool desc);
    void shuffleInitializer(std::promise<void>&& promise, int i, int delay);
    void checkThreadProgress();

    void shuffleLists(int delay);
    void performActions();

    void handleEvents();
    void draw();
};

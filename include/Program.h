#include <SFML/Graphics.hpp>
#include <string>
#include <stack>
#include <future>

#include "NormalPattern.h"

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
    ~Program();
    void update();
    void performActions();
private:
    void destroyAlgorithmList(SortingAlgorithm* algoList[]);
    void initializer(std::promise<void>&& promise, int i, bool desc);
    void checkThreadProgress();
    // void initializeList(ElementList& elements);
    // void initializeLists(int no);
    void handleEvents();
    void draw();
};

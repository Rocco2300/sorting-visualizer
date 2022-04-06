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
};

class Program
{
private:
    sf::RenderWindow window;
    sf::Clock clock;

    std::thread thread;
    std::thread thread1;
    std::vector<ElementList> elemLists;
    std::stack<Action> actions;

    const char* algorithmIndexes[7];
    SortingAlgorithm* sortingAlgorithm;
    SortingAlgorithm* algorithmList[7];
    
    int delay;
    int elementNo;
    int listNumber;
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
    void initializeList(ElementList& elements);
    void initializeLists(std::vector<ElementList>& elemLists, int no);
    void handleEvents();
    void draw();
};

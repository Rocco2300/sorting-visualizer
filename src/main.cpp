#include "Program.h"

int main()
{
    // Suppres false Failed to set DirectInput device axis mode: 1 error 
    sf::err().rdbuf(nullptr);

    Program program;
    program.update();
    return 0;
}
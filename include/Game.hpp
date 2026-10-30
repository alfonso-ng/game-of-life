#ifndef GAME_H
#define GAME_H

#include "Grid.hpp"
#include "Vec2List.hpp"

class Game
{
private:
    Grid grid;

public:
    Game(int rows, int cols, Vec2List& initial_cells);
    ~Game();

    void drawBoard();
    void simulateStep();
    void simulate();
};

#endif

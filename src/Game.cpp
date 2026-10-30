#include "Game.hpp"
#include <cstdlib>
#include <unistd.h>

Game::Game(int _rows, int _cols, Vec2List& initial_cells)
    : grid(_rows, _cols)
{
    grid.populateGrid(initial_cells);
}

Game::~Game()
{

}

void Game::drawBoard()
{
    grid.drawGrid();
}

void Game::simulateStep()
{
    int rows, cols;
    int n_neighbors;
    rows = grid.getRows();
    cols = grid.getCols();


    Grid tmpGrid = Grid(grid);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            n_neighbors = grid.countNeighbors({i, j});
            if (n_neighbors < 2 || n_neighbors > 4) {
                tmpGrid.setCell({i, j}, 0);
            }
            else if (n_neighbors == 3) tmpGrid.setCell({i, j}, 1);
        }
    }

    grid = tmpGrid;
}

void Game::simulate()
{
    while (true)
    {
        system("clear");
        drawBoard();
        simulateStep();
        sleep(1);
    }
}

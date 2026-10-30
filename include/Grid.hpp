#ifndef GRID_H
#define GRID_H

#include "Matrix.hpp"
#include "Vec2List.hpp"

class Grid
{
private:
    int rows;
    int cols;
    Matrix grid;

public:
    Grid(int rows, int cols);
    Grid(const Grid& other);
    ~Grid();

    int getRows();
    int getCols();
    void setCell(vec2 cell, int value);
    bool isCellColored(vec2 cell);

    void drawGrid();
    void populateGrid(Vec2List& cells);
    int countNeighbors(vec2 cell);
};

#endif

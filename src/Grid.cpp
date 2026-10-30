#include "Grid.hpp"
#include "Vec2List.hpp"
#include <iostream>

Grid::Grid(int _rows, int _cols)
    : grid(_rows, _cols, 0)
{
    rows = _rows;
    cols = _cols;
}

Grid::Grid(const Grid& other)
    : rows(other.rows),
      cols(other.cols),
      grid(other.grid)
{
}

Grid::~Grid()
{

}

int Grid::getRows()
{
    return rows;
}

int Grid::getCols()
{
    return cols;
}

void Grid::setCell(vec2 cell, int value)
{
    grid(cell.x, cell.y) = value;
}

bool Grid::isCellColored(vec2 cell)
{
    return grid(cell.x, cell.y);
}

void Grid::drawGrid()
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << ((grid(i, j) ? "██" : "  "));
        }
        std::cout << std::endl;
    }
}

void Grid::populateGrid(Vec2List& cells)
{
    int row, col;
    vec2 cell;
    for (int i = 0; i < cells.getSize(); i++) {
        cell = cells.item_at(i);
        row = cell.x;
        col = cell.y;
        grid(row, col) = 1;
    }
}

int Grid::countNeighbors(vec2 cell)
{
    int row, col;
    row = cell.x;
    col = cell.y;
    int count = 0;

    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (!(row+i < 0 || row+i >= rows || col+j < 0 || col+j >= cols || (i == 0 && j == 0))) {
                //std::cout << "Row: " << row+i << ", Col: " << col+j
                if (grid(row+i, col+j)) count++;
            }
        }
    }
    return count;
}

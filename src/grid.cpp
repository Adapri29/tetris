#include "grid.hpp"

Grid::Grid(int nRows, int nColumns, int cellSize)
    : nRows(nRows), nColumns(nColumns), cellSize(cellSize)
{
    grid.resize(nRows, std::vector<int>(nColumns, 0));
    colors = GetCellColors();
}

void Grid::Print() const
{
    for (int row = 0; row < nRows; row++)
    {
        for (int column = 0; column < nColumns; column++)
        {
            std::cout << grid[row][column] << " ";
        }

        std::cout << std::endl;
    }
}

void Grid::SetValue(int row, int column, int value)
{
    grid[row][column] = value;
}

int Grid::GetValue(int row, int column) const
{
    return grid[row][column];
}

void Grid::Draw() const
{
    for (int row = 0; row < nRows; row++)
    {
        for (int column = 0; column < nColumns; column++)
        {
            int cellValue = GetValue(row, column);
            DrawRectangle(column * cellSize + 1, row * cellSize + 1, cellSize - 1, cellSize - 1, colors[cellValue]);
        }

        std::cout << std::endl;
    }
}
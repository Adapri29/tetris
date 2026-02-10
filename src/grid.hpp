#pragma once
#include "colors.hpp"
#include <vector>
#include "raylib.h"
#include <iostream>

class Grid
{
private:
    int nRows;
    int nColumns;
    int cellSize;

    std::vector<std::vector<int>> grid;
    std::vector<Color> colors;

public:
    Grid(int nRows, int nColumns, int cellSize);

    void SetValue(int row, int column, int value);
    int GetValue(int row, int column) const;

    void Print() const;
    void Draw() const;
};
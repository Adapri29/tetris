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

    void ClearRow(int row);
    void MoveRowDown(int row, int numRows);
    bool IsRowFull(int row);

    public:
    Grid(int nRows, int nColumns, int cellSize);

    void Inicialize();
    
    bool IsCellOutside(int row, int column);
    bool IsCellEmpty(int row, int column);

    int ClearFullRows();

    void SetValue(int row, int column, int value);
    int GetValue(int row, int column) const;

    void Print() const;
    void Draw() const;
};
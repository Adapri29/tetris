#include "grid.hpp"
#include <iostream>
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

bool Grid::IsCellOutside(int row, int column){
    if (column < 0 || column >= nColumns) return true;
    if (row >= nRows) return true;
    return false;
}

bool Grid::IsCellEmpty(int row, int column){
    if (row < 0) return true;
    if (IsCellOutside(row, column)) return false; 
    return grid[row][column] == 0;
}

bool Grid::IsRowFull(int row){
    for(int column=0; column<nColumns; column++){
        if(IsCellEmpty(row, column)){
            return false;
        }
    }
    return true;
}

void Grid::ClearRow(int row){
    for(int column=0; column<nColumns; column++){
        SetValue(row, column, 0);
    }
}

void Grid::MoveRowDown(int row, int numRows){
    for(int column=0; column<nColumns; column++){
        SetValue(row+numRows, column, GetValue(row, column));
        SetValue(row, column, 0);
    }
}

int Grid::ClearFullRows(){
    int completed = 0;

    for(int row = nRows-1; row>=0; row--){
        if(IsRowFull(row)){
            ClearRow(row);
            completed++;
        }
        else if(completed>0){
            MoveRowDown(row, completed);
        }
    }

    return completed;
}

void Grid::Draw() const
{
    for (int row = 0; row < nRows; row++)
    {
        for (int column = 0; column < nColumns; column++)
        {
           
            int cellValue = GetValue(row, column);
            DrawRectangle(column * cellSize + 11, row * cellSize + 11, cellSize - 1, cellSize - 1, colors[cellValue]);
        }
    }
}
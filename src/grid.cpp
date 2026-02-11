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
    if(row < 0 || row >= nRows) return true;
    if(column<0 || column >= nColumns) return true;

    return false;
}

bool Grid::IsCellEmpty(int row, int column){
    if(GetValue(row, column) == 0){
        return true;
    }
    
    return false;
}

bool Grid::IsRowFull(int row){
    std::cout<<"Row: "<<row<<std::endl;
    for(int column=0; column<nColumns; column++){
        if(IsCellEmpty(row, column)){
            std::cout<<"No full"<<row<<std::endl;
            return false;
        }
    }
    std::cout<<"full"<<row<<std::endl;
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
    std::cout<<"Comprobar filas"<<std::endl;
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
            DrawRectangle(column * cellSize + 1, row * cellSize + 1, cellSize - 1, cellSize - 1, colors[cellValue]);
        }

        std::cout << std::endl;
    }
}
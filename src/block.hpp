#pragma once
#include <map>
#include <vector>
#include "raylib.h"
#include "position.hpp"
#include "colors.hpp"

class Block
{

protected:
    int id;
    int rotationState;
    Position position;
    int cellSize;
    Color color;

    std::map<int, std::vector<Position>> cells;

    std::vector<Position> GetCellPositions() const;

public:
    Block(Position position, int cellSize);
    void Rotate();
    void Move(int row, int column);
    void Draw() const;
};
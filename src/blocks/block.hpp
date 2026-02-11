#pragma once
#include <map>
#include <vector>
#include "raylib.h"
#include "../position.hpp"
#include "../colors.hpp"

class Block
{

protected:
    int id_;
    int rotationState;
    Position position;
    int cellSize;
    Color color;

    std::map<int, std::vector<Position>> cells;
    
public:
    Block(int cellSize);
    std::vector<Position> GetCellPositions() const;
    int id() const {return id_;};
    void Rotate();
    void UndoRotate();
    void Move(Position direction);
    void Draw() const;
};
#include "block.hpp"

Block::Block(int cellSize) : position({-1, 4}), cellSize(cellSize)
{

    this->rotationState = 0;
};

std::vector<Position> Block::GetCellPositions() const
{
    std::vector<Position> tiles = cells.at(rotationState);
    std::vector<Position> movedTiles;

    for (Position item : tiles)
    {
        Position newPos = item + position;
        movedTiles.push_back(newPos);
    }

    return movedTiles;
}

void Block::Rotate()
{
    rotationState = (rotationState + 1) % 4;
}

void Block::UndoRotate()
{
    rotationState = (rotationState - 1 + 4) % 4;
}

void Block::Move(Position direction){
    position = position + direction;
}

void Block::Draw() const
{

    std::vector<Position> tiles = GetCellPositions();

    for (Position item : tiles)
    {
        if(item.row < 0) continue;
        DrawRectangle(item.column * cellSize + 11, item.row * cellSize + 11, cellSize - 1, cellSize - 1, color);
    }
}

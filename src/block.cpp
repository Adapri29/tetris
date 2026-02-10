#include "block.hpp"

Block::Block(Position position, int cellSize) : position(position), cellSize(cellSize)
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

void Block::Draw() const
{

    std::vector<Position> tiles = GetCellPositions();

    for (Position item : tiles)
    {
        DrawRectangle(item.column * cellSize + 1, item.row * cellSize + 1, cellSize - 1, cellSize - 1, color);
    }
}

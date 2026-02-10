

#pragma once
#include "../block.hpp"
#include "../colors.hpp"

class LBlock : public Block
{
public:
    LBlock(Position position, int cellSize) : Block(position, cellSize)
    {
        id = 2;

        cells[0] = {{1, 0}, {1, 1}, {1, 2}, {0, 2}};
        cells[1] = {{0, 1}, {1, 1}, {2, 1}, {2, 2}};
        cells[2] = {{1, 0}, {1, 1}, {1, 2}, {2, 0}};
        cells[3] = {{0, 1}, {1, 1}, {2, 1}, {0, 0}};

        color = GetCellColors()[id];
    }
};


#pragma once
#include "../block.hpp"
#include "../colors.hpp"

class SBlock : public Block
{
public:
    SBlock(Position position, int cellSize) : Block(position, cellSize)
    {
        id = 4;

        cells[0] = {{1, 0}, {1, 1}, {0, 1}, {0, 2}};
        cells[1] = {{0, 0}, {1, 0}, {1, 1}, {2, 1}};
        cells[2] = {{1, 0}, {1, 1}, {0, 1}, {0, 2}};
        cells[3] = {{0, 0}, {1, 0}, {1, 1}, {2, 1}};

        color = GetCellColors()[id];
    }
};
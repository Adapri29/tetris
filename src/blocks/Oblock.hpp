

#pragma once
#include "../block.hpp"
#include "../colors.hpp"

class OBlock : public Block
{
public:
    OBlock(Position position, int cellSize) : Block(position, cellSize)
    {
        id = 3;

        cells[0] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
        cells[1] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
        cells[2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
        cells[3] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};

        color = GetCellColors()[id];
    }
};
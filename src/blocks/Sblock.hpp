

#pragma once
#include "block.hpp"
#include "../colors.hpp"

class SBlock : public Block
{
public:
    SBlock(int cellSize) : Block(cellSize)
    {
        id_ = 2;

        cells[0] = {{1, 0}, {1, 1}, {0, 1}, {0, 2}};
        cells[1] = {{0, 0}, {1, 0}, {1, 1}, {2, 1}};
        cells[2] = {{1, 0}, {1, 1}, {0, 1}, {0, 2}};
        cells[3] = {{0, 0}, {1, 0}, {1, 1}, {2, 1}};

        color = GetCellColors()[id_];

        position = {-1, 4};
    }
};
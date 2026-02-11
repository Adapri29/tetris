

#pragma once
#include "block.hpp"
#include "../colors.hpp"

class TBlock : public Block
{
public:
    TBlock(int cellSize) : Block(cellSize)
    {
        id_ = 6;

        cells[0] = {{0, 1}, {1, 0}, {1, 1}, {1, 2}};
        cells[1] = {{0, 1}, {1, 1}, {2, 1}, {1, 2}};
        cells[2] = {{2, 1}, {1, 0}, {1, 1}, {1, 2}};
        cells[3] = {{0, 1}, {1, 1}, {2, 1}, {1, 0}};

        color = GetCellColors()[id_];
    }
};
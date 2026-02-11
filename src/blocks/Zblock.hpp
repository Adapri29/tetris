

#pragma once
#include "block.hpp"
#include "../colors.hpp"

class ZBlock : public Block
{
public:
    ZBlock(int cellSize) : Block(cellSize)
    {
        id_ = 3;

        cells[0] = {{1, 2}, {1, 1}, {0, 1}, {0, 0}};
        cells[1] = {{0, 2}, {1, 2}, {1, 1}, {2, 1}};
        cells[2] = {{1, 2}, {1, 1}, {0, 1}, {0, 0}};
        cells[3] = {{0, 2}, {1, 2}, {1, 1}, {2, 1}};

        color = GetCellColors()[id_];

        position = {-1, 4};
    }
};
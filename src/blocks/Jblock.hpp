

#pragma once
#include "block.hpp"
#include "../colors.hpp"

class JBlock : public Block
{
public:
    JBlock(int cellSize) : Block(cellSize)
    {
        id_ = 4;

        cells[0] = {{1, 0}, {1, 1}, {1, 2}, {2, 2}};
        cells[1] = {{0, 1}, {1, 1}, {2, 1}, {2, 0}};
        cells[2] = {{1, 0}, {1, 1}, {1, 2}, {0, 0}};
        cells[3] = {{0, 1}, {1, 1}, {2, 1}, {0, 2}};

        color = GetCellColors()[id_];

        position = {-2, 4};
    }
};


#pragma once
#include "block.hpp"
#include "../colors.hpp"

class LBlock : public Block
{
public:
    LBlock(int cellSize) : Block(cellSize)
    {
        id_ = 1;

        cells[0] = {{1, 0}, {1, 1}, {1, 2}, {2, 0}};
        cells[1] = {{0, 1}, {1, 1}, {2, 1}, {0, 0}};
        cells[2] = {{1, 0}, {1, 1}, {1, 2}, {0, 2}};
        cells[3] = {{0, 1}, {1, 1}, {2, 1}, {2, 2}};

        color = GetCellColors()[id_];

        position={-1, 4};
    }
};
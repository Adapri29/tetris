

#pragma once
#include "block.hpp"
#include "../colors.hpp"

class IBlock : public Block
{
public:
    IBlock(int cellSize) : Block(cellSize)
    {
        id_ = 7;

        cells[0] = {{1, 0}, {1, 1}, {1, 2}, {1, 3}};
        cells[1] = {{0, 2}, {1, 2}, {2, 2}, {3, 2}};
        cells[2] = {{2, 0}, {2, 1}, {2, 2}, {2, 3}};
        cells[3] = {{0, 1}, {1, 1}, {2, 1}, {3, 1}};

        color = GetCellColors()[id_];

        position={-1, 3};
    }
};
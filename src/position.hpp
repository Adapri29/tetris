
#pragma once

class Position
{
public:
    int row;
    int column;
    Position(int row, int column);
    Position operator+(const Position &other) const;
};
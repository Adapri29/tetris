#include "position.hpp"

Position::Position(int row, int column) : row(row), column(column) {};

Position Position::operator+(const Position &other) const
{
    return Position(this->row + other.row, this->column + other.column);
}
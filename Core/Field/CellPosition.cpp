#include <iostream>

#include "../Includes/CellPosition.h"

CellPosition::CellPosition()
{
    row = 0;
    column = 0;
}

CellPosition::CellPosition(size_t cellRow, size_t cellColumn)
{
    row = cellRow;
    column = cellColumn;
}

size_t CellPosition::getRow() const
{
    return row;
}

size_t CellPosition::getColumn() const
{
    return column;
}
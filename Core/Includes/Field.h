#ifndef TICTACTOE_FIELD_H
#define TICTACTOE_FIELD_H

#include <iostream>

#include "CellPosition.h"
#include "CellValues.h"

class Field
{
    private:
        size_t size;
        Cell::Values **fieldMatrix;
    public:
        Field();

        explicit Field(size_t fieldSize);

        ~Field();

        size_t getSize() const;

        Cell::Values getCellValue(CellPosition position);

        void changeCellValue(Cell::Values value, CellPosition);
};

#endif //TICTACTOE_FIELD_H

#include <string>

#include "../Includes/Field.h"
#include "../Includes/InvalidCellValueException.h"

Field::Field()
{
    size = 0;
    fieldMatrix = nullptr;
}

Field::Field(size_t fieldSize)
{
    size = fieldSize;

    fieldMatrix = new Cell::Values *[size];

    for (size_t row = 0; row < size; row++) {
        fieldMatrix[row] = new Cell::Values[size];

        for (size_t column = 0; column < size; column++) {
            fieldMatrix[row][column] = Cell::Values::EMPTY;
        }
    }
}

Field::~Field()
{
    for (size_t row = 0; row < size; row++) {
        delete[] fieldMatrix[row];
    }
}

size_t Field::getSize() const
{
    return size;
}

Cell::Values Field::getCellValue(CellPosition position)
{
    return fieldMatrix[position.getRow()][position.getColumn()];
}


void Field::changeCellValue(Cell::Values value, CellPosition position)
{
    if (value == Cell::Values::EMPTY) {
        throw InvalidCellValueException(Cell::Values::EMPTY);
    }

    if (fieldMatrix[position.getRow()][position.getColumn()] != Cell::Values::EMPTY) {
        throw InvalidCellValueException(value);
    }


    fieldMatrix[position.getRow()][position.getColumn()] = value;
}
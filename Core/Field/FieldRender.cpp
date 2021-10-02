#include <iostream>

#include "../Includes/FieldRender.h"

void FieldRender::render(Field *field)
{
    for (size_t row = 0; row < field->getSize(); row++) {
        std::cout << '|' << ' ';

        for (size_t column = 0; column < field->getSize(); column++) {
            if (column > 0) {
                std::cout << " ";
            }

            renderCell(field, CellPosition(row, column));
        }
        std::cout << ' ' << '|';

        std::cout << std::endl;
    }
}

void FieldRender::renderCell(Field *field, CellPosition position)
{
    auto cellValue = field->getCellValue(position);

    if (cellValue == Cell::EMPTY) {
        std::cout << '_';
    } else if (cellValue == Cell::CROSS) {
        std::cout << 'x';
    } else if (cellValue == Cell::ZERO) {
        std::cout << '0';
    }
}
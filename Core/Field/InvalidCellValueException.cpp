#include "../Includes/InvalidCellValueException.h"

InvalidCellValueException::InvalidCellValueException()
{
    value = Cell::Values::EMPTY;
    message = "You cannot set field cell";
}

InvalidCellValueException::InvalidCellValueException(Cell::Values cellValue)
{
    value = cellValue;
    message = "You cannot set field cell";
}

const char *InvalidCellValueException::what()
{
    message = "You cannot set field cell with " + std::string(1, (char) value) + ".";

    return message.c_str();
}
#ifndef TICTACTOE_INVALIDCELLEXCEPTION_H
#define TICTACTOE_INVALIDCELLEXCEPTION_H

#include <string>

#include "CellValues.h"

class InvalidCellValueException : public std::exception
{
    private:
        Cell::Values value;
        std::string message;
    public:
        InvalidCellValueException();

        InvalidCellValueException(Cell::Values cellValue);

        const char *what();
};

#endif //TICTACTOE_INVALIDCELLEXCEPTION_H
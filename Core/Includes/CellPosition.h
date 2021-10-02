#ifndef TICTACTOE_CELLPOSITION_H
#define TICTACTOE_CELLPOSITION_H

#include <iostream>

class CellPosition
{
    private:
        size_t row;
        size_t column;

    public:
        CellPosition();

        CellPosition(size_t cellRow, size_t cellColumn);

        size_t getRow() const;

        size_t getColumn() const;
};


#endif //TICTACTOE_CELLPOSITION_H

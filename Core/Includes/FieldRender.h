#ifndef TICTACTOE_FIELDRENDER_H
#define TICTACTOE_FIELDRENDER_H

#include "Field.h"

class FieldRender
{
    public:
        static void render(Field *field);

    private:
        static void renderCell(Field *field, CellPosition position);
};

#endif //TICTACTOE_FIELDRENDER_H
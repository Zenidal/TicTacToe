#ifndef TICTACTOE_PLAYER_H
#define TICTACTOE_PLAYER_H

#include "Field.h"
#include "CellPosition.h"
#include "CellValues.h"
#include "PlayerSide.h"

class Player
{
    public:
        Player();

        explicit Player(const std::string& playerName, PlayerSide::Side side);

        void makeTurn(Field *field);

        std::string getName();
        PlayerSide::Side getSide();

    private:
        std::string name;
        PlayerSide::Side playerSide;

        CellPosition *choosePositionForTurn(Field * field);

        Cell::Values convertPlayerSideToCellValue();
};

#endif //TICTACTOE_PLAYER_H
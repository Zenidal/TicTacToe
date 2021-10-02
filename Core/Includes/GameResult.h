#ifndef TICTACTOE_GAMERESULT_H
#define TICTACTOE_GAMERESULT_H

#include "Player.h"

struct GameResult
{
    enum RESULTS
    {
        HAS_MOVES,
        DRAW,
        WIN
    };

    RESULTS result;
    PlayerSide::Side winner;

    bool hasWinner() const
    {
        return result == WIN;
    }
};


#endif //TICTACTOE_GAMERESULT_H

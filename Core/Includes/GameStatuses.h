#ifndef TICTACTOE_GAMESTATUSES_H
#define TICTACTOE_GAMESTATUSES_H

struct GameStatuses
{
    enum Status
    {
        CREATED,
        STARTED,
        IN_PROGRESS,
        DRAW,
        WON
    };
};

#endif //TICTACTOE_GAMESTATUSES_H

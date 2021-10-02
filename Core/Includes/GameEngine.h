#ifndef TICTACTOE_GAMEENGINE_H
#define TICTACTOE_GAMEENGINE_H

#include "Player.h"
#include "GameStatus.h"
#include "GameStatuses.h"
#include "GameResult.h"
#include "GameResultCalculator.h"

class GameEngine
{
    private:
        Player *winner;
        Player *turn;
        Player player1;
        Player player2;
        GameStatus gameStatus;
        GameResultCalculator resultCalculator;

        void changeTurn();

    public:
        GameEngine();

        void createPlayers();

        GameStatus makeTurn(Field *field);

        GameStatus getStatus();

        Player * getWinner();

        void finishGame(const GameResult &result);
};

#endif //TICTACTOE_GAMEENGINE_H
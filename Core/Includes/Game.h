#ifndef TICTACTOE_GAME_H
#define TICTACTOE_GAME_H

#include "Field.h"
#include "FieldRender.h"
#include "GameEngine.h"
#include "GameStatuses.h"

class Game
{
    private:
        Field *field;
        FieldRender fieldRender;
        GameEngine gameEngine;

    public:
        Game();

        explicit Game(size_t size);

        ~Game();

        void startGame();

        GameStatus makeTurn();

        Player * getWinner();

        void renderField();

        static void renderErrorMessage(const std::string& message);
};

#endif //TICTACTOE_GAME_H
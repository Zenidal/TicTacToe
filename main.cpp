#include <iostream>

#include "Core/Includes/Game.h"

int main()
{
    // we can select game size in range from 0 to size_t limit (but I would not try :=) )
    auto game = new Game(4);

    game->startGame();
    game->renderField();

    GameStatus status;

    // I couldn't clear console because after execution of system("CLS") field doesn't display

    do {
        status = game->makeTurn();

        game->renderField();
    } while (!status.isGameFinished());

    if (status.getStatus() == GameStatuses::WON) {
        std::cout << game->getWinner()->getName() + "won. Congratulations to the winner." << std::endl;
    } else {
        std::cout << "The game ended in a draw.";
    }

    delete game;

    return 0;
}

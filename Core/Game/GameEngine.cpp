#include "../Includes/GameEngine.h"
#include "../Includes/MoveException.h"

GameEngine::GameEngine()
{
    winner = nullptr;
    turn = nullptr;
    resultCalculator = GameResultCalculator();
    gameStatus = GameStatus();
}

void GameEngine::changeTurn()
{
    if (turn == &player1) {
        turn = &player2;
    } else {
        turn = &player1;
    }
}

void GameEngine::createPlayers()
{
    player1 = Player("Player 1", PlayerSide::Side::USE_CROSS);
    player2 = Player("Player 2", PlayerSide::Side::USE_ZERO);

    turn = &player1;

    gameStatus.changeStatus(GameStatuses::Status::STARTED);
    gameStatus.changeStatus(GameStatuses::Status::IN_PROGRESS);
}

GameStatus GameEngine::makeTurn(Field *field)
{
    if (GameStatuses::IN_PROGRESS != gameStatus.getStatus()) {
        throw MoveException(MoveExceptionReasons::INVALID_GAME_STATUS);
    }

    turn->makeTurn(field);

    auto result = resultCalculator.getResult(field);
    if (result.result != GameResult::HAS_MOVES) {
        finishGame(result);
    } else {
        changeTurn();
    }

    return gameStatus;
}

GameStatus GameEngine::getStatus()
{
    return gameStatus;
}

Player *GameEngine::getWinner()
{
    return winner;
}

void GameEngine::finishGame(const GameResult &result)
{
    if (result.hasWinner()) {
        auto player1Won = result.winner == player1.getSide();

        winner = player1Won ? &player1 : &player2;

        gameStatus.changeStatus(GameStatuses::WON);
    } else {
        gameStatus.changeStatus(GameStatuses::DRAW);
    }
}
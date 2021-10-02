#include "../Includes/Game.h"
#include "../Includes/MoveException.h"

Game::Game()
{
    field = new Field();
    fieldRender = FieldRender();
    gameEngine = GameEngine();
};

Game::Game(size_t size)
{
    field = new Field(size);
    fieldRender = FieldRender();
    gameEngine = GameEngine();
}

Game::~Game()
{
    delete field;
}

void Game::startGame()
{
    gameEngine.createPlayers();
}

GameStatus Game::makeTurn()
{
    try {
        auto status = gameEngine.makeTurn(field);

        return status;
    } catch (MoveException &e) {
        renderErrorMessage(e.what());

        return gameEngine.getStatus();
    }
}

Player *Game::getWinner()
{
    return gameEngine.getWinner();
}

void Game::renderField()
{
    FieldRender::render(field);
}

void Game::renderErrorMessage(const std::string &message)
{
    std::cout << "------ERROR------" << std::endl << message << std::endl << "------ERROR------" << std::endl;
}
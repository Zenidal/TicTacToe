#include <iostream>

#include "../Includes/Player.h"
#include "../Includes/InvalidCellValueException.h"
#include "../Includes/MoveException.h"

Player::Player()
{
    playerSide = PlayerSide::USE_CROSS;
}

Player::Player(const std::string &playerName, PlayerSide::Side side)
{
    name = playerName;
    playerSide = side;
}

void Player::makeTurn(Field *field)
{
    auto position = choosePositionForTurn(field);

    try {
        field->changeCellValue(convertPlayerSideToCellValue(), *position);
    } catch (InvalidCellValueException &e) {
        delete position;

        throw MoveException(MoveExceptionReasons::INVALID_MOVE_CELL);
    }

    delete position;
}

std::string Player::getName()
{
    return name;
}

PlayerSide::Side Player::getSide()
{
    return playerSide;
}

CellPosition *Player::choosePositionForTurn(Field *field)
{
    size_t row;
    size_t column;

    do {
        std::cout << name << " moves (" << ((playerSide == PlayerSide::USE_CROSS) ? 'x' : '0') << ")."<< std::endl;

        std::cout << "Please input row for turn:";
        std::cin >> row;

        std::cout << "Please input column for turn:";
        std::cin >> column;
    } while (row > field->getSize() || row < 1 || column > field->getSize() || column < 1);

    std::cout << std::endl;

    return new CellPosition(row - 1, column - 1);
}

Cell::Values Player::convertPlayerSideToCellValue()
{
    if (playerSide == PlayerSide::Side::USE_ZERO) {
        return Cell::Values::ZERO;
    }
    if (playerSide == PlayerSide::Side::USE_CROSS) {
        return Cell::Values::CROSS;
    }

    throw std::exception();
}

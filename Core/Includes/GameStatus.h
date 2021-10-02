#ifndef TICTACTOE_GAMESTATUS_H
#define TICTACTOE_GAMESTATUS_H

#include <map>
#include <vector>

#include "GameStatuses.h"

class InvalidStatusException : public std::exception
{
    private:
        GameStatuses::Status oldStatus;
        GameStatuses::Status newStatus;

    public:
        explicit InvalidStatusException(GameStatuses::Status oldValue, GameStatuses::Status newValue);

        const char *what();
};

class GameStatus
{
    private:
        GameStatuses::Status status;
        std::map<GameStatuses::Status, std::vector<GameStatuses::Status> > possibleTransitions;

        bool canChangeStatus(GameStatuses::Status newStatus);

    public:
        GameStatus();

        void changeStatus(GameStatuses::Status newStatus);

        GameStatuses::Status getStatus();

        bool isGameFinished();
};

#endif //TICTACTOE_GAMESTATUS_H
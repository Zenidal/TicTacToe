#include "../Includes/GameStatus.h"

InvalidStatusException::InvalidStatusException(GameStatuses::Status oldValue, GameStatuses::Status newValue)
{
    oldStatus = oldValue;
    newStatus = newValue;
}

const char *InvalidStatusException::what()
{
    return "You cannot change status to this new status.";
}


bool GameStatus::canChangeStatus(GameStatuses::Status newStatus)
{
    auto possibleStatuses = possibleTransitions[status];

    for (auto possibleStatus: possibleStatuses) {
        if (possibleStatus == newStatus) {
            return true;
        }
    }

    return false;
}

GameStatus::GameStatus()
{
    status = GameStatuses::Status::CREATED;

    possibleTransitions[GameStatuses::Status::CREATED] = {GameStatuses::Status::STARTED};
    possibleTransitions[GameStatuses::Status::STARTED] = {GameStatuses::Status::IN_PROGRESS};
    possibleTransitions[GameStatuses::Status::IN_PROGRESS] = {GameStatuses::Status::DRAW, GameStatuses::WON};
}

void GameStatus::changeStatus(GameStatuses::Status newStatus)
{
    if (!canChangeStatus(newStatus)) {
        throw InvalidStatusException(status, newStatus);
    }
    status = newStatus;
}

GameStatuses::Status GameStatus::getStatus()
{
    return status;
}

bool GameStatus::isGameFinished()
{
    return status == GameStatuses::Status::DRAW || status == GameStatuses::WON;
}
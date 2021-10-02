#include "../Includes/MoveException.h"

MoveException::MoveException()
{
    reason = MoveExceptionReasons::UNDEFINED_REASON;
};

MoveException::MoveException(MoveExceptionReasons::REASONS exceptionReason)
{
    reason = exceptionReason;
}

const char *MoveException::what()
{
    if (reason == MoveExceptionReasons::INVALID_MOVE_CELL) {
        return "You can not move to that cell.";
    }

    if (reason == MoveExceptionReasons::INVALID_GAME_STATUS) {
        return "Game is in invalid status for moves.";
    }

    return "Undefined reason.";
}
#ifndef TICTACTOE_MOVEEXCEPTION_H
#define TICTACTOE_MOVEEXCEPTION_H

#include <iostream>

#include "MoveExceptionReasons.h"

class MoveException : public std::exception
{
    private:
        MoveExceptionReasons::REASONS reason;
    public:
        MoveException();

        MoveException(MoveExceptionReasons::REASONS exceptionReason);

        const char *what();
};

#endif //TICTACTOE_MOVEEXCEPTION_H

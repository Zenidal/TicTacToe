#ifndef TICTACTOE_GAMERESULTCALCULATOR_H
#define TICTACTOE_GAMERESULTCALCULATOR_H

#include "GameResult.h"

#define CalculationArray std::map<std::string, std::map<size_t, size_t[2]> >

class GameResultCalculator
{
    public:
        static GameResult getResult(Field *field);

    private:
        static void initCalculationArrays(
            size_t fieldSize,
            std::map<size_t, size_t[2]> &crossRowPotentialMoves,
            std::map<size_t, size_t[2]> &crossColumnPotentialMoves,
            std::map<size_t, size_t[2]> &crossDiagonalPotentialMoves,
            std::map<size_t, size_t[2]> &zeroRowPotentialMoves,
            std::map<size_t, size_t[2]> &zeroColumnPotentialMoves,
            std::map<size_t, size_t[2]> &zeroDiagonalPotentialMoves
        );

        static void calculateArrays(
            Field *field,
            std::map<size_t, size_t[2]> &crossRowPotentialMoves,
            std::map<size_t, size_t[2]> &crossColumnPotentialMoves,
            std::map<size_t, size_t[2]> &crossDiagonalPotentialMoves,
            std::map<size_t, size_t[2]> &zeroRowPotentialMoves,
            std::map<size_t, size_t[2]> &zeroColumnPotentialMoves,
            std::map<size_t, size_t[2]> &zeroDiagonalPotentialMoves
        );

        static void calculateResultValues(std::map<size_t, size_t[2]> &array, size_t fieldSize, bool &won, bool &hasMoves);

        static GameResult makeResult(const bool &crossHasMoves, const bool &zeroHasMoves, const bool &crossWon, const bool &zeroWon);

        //for debug purposes
        static void showArray(const std::string &arrayName, std::map<size_t, size_t[2]> &array);
};


#endif //TICTACTOE_GAMERESULTCALCULATOR_H

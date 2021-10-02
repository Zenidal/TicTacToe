#include <map>

#include "../Includes/GameResultCalculator.h"

void GameResultCalculator::initCalculationArrays(
    size_t fieldSize,
    std::map<size_t, size_t[2]> &crossRowPotentialMoves,
    std::map<size_t, size_t[2]> &crossColumnPotentialMoves,
    std::map<size_t, size_t[2]> &crossDiagonalPotentialMoves,
    std::map<size_t, size_t[2]> &zeroRowPotentialMoves,
    std::map<size_t, size_t[2]> &zeroColumnPotentialMoves,
    std::map<size_t, size_t[2]> &zeroDiagonalPotentialMoves
)
{
    //the first element from massive is responsible for line availability, the second one is responsible for fullness

    //the first diagonal is straight, the second one is reverse
    crossDiagonalPotentialMoves[0][0]
        = crossDiagonalPotentialMoves[1][0]
        = zeroDiagonalPotentialMoves[0][0]
        = zeroDiagonalPotentialMoves[1][0]
        = 1;

    crossDiagonalPotentialMoves[0][1]
        = crossDiagonalPotentialMoves[1][1]
        = zeroDiagonalPotentialMoves[0][1]
        = zeroDiagonalPotentialMoves[1][1]
        = 0;

    for (int i = 0; i < fieldSize; ++i) {
        crossRowPotentialMoves[i][0] = 1;
        crossRowPotentialMoves[i][1] = 0;
        crossColumnPotentialMoves[i][0] = 1;
        crossColumnPotentialMoves[i][1] = 0;
        zeroRowPotentialMoves[i][0] = 1;
        zeroRowPotentialMoves[i][1] = 0;
        zeroColumnPotentialMoves[i][0] = 1;
        zeroColumnPotentialMoves[i][1] = 0;
    }
}

void GameResultCalculator::calculateArrays(
    Field *field,
    std::map<size_t, size_t[2]> &crossRowPotentialMoves,
    std::map<size_t, size_t[2]> &crossColumnPotentialMoves,
    std::map<size_t, size_t[2]> &crossDiagonalPotentialMoves,
    std::map<size_t, size_t[2]> &zeroRowPotentialMoves,
    std::map<size_t, size_t[2]> &zeroColumnPotentialMoves,
    std::map<size_t, size_t[2]> &zeroDiagonalPotentialMoves)
{
    for (size_t row = 0; row < field->getSize(); row++) {
        for (size_t column = 0; column < field->getSize(); column++) {
            auto value = field->getCellValue(CellPosition(row, column));

            if (value == Cell::EMPTY) {
                continue;
            }

            if (value == Cell::CROSS) {
                zeroRowPotentialMoves[row][0] = 0;
                zeroColumnPotentialMoves[column][0] = 0;

                zeroRowPotentialMoves[row][1] = zeroRowPotentialMoves[row][1] > 0 ? --zeroRowPotentialMoves[row][1] : 0;
                crossRowPotentialMoves[row][1]++;

                zeroColumnPotentialMoves[column][1] = zeroColumnPotentialMoves[column][1] > 0 ? --zeroColumnPotentialMoves[column][1] : 0;
                crossColumnPotentialMoves[column][1]++;

                if (row == column) {
                    zeroDiagonalPotentialMoves[0][0] = 0;

                    zeroDiagonalPotentialMoves[0][1] = zeroDiagonalPotentialMoves[0][1] > 0 ? --zeroDiagonalPotentialMoves[0][1] : 0;
                    crossDiagonalPotentialMoves[0][1]++;
                }
                if ((row + column) == (field->getSize() - 1)) {
                    zeroDiagonalPotentialMoves[1][0] = 0;

                    zeroDiagonalPotentialMoves[1][1] = zeroDiagonalPotentialMoves[1][1] > 0 ? --zeroDiagonalPotentialMoves[1][1] : 0;
                    crossDiagonalPotentialMoves[1][1]++;
                }
            } else {
                crossRowPotentialMoves[row][0] = 0;
                crossColumnPotentialMoves[column][0] = 0;

                crossRowPotentialMoves[row][1] = crossRowPotentialMoves[row][1] > 0 ? --crossRowPotentialMoves[row][1] : 0;
                zeroRowPotentialMoves[row][1]++;

                crossColumnPotentialMoves[column][1] = crossColumnPotentialMoves[column][1] > 0 ? --crossColumnPotentialMoves[column][1] : 0;
                zeroColumnPotentialMoves[column][1]++;

                if (row == column) {
                    crossDiagonalPotentialMoves[0][0] = 0;

                    crossDiagonalPotentialMoves[0][1] = crossDiagonalPotentialMoves[0][1] > 0 ? --crossDiagonalPotentialMoves[0][1] : 0;
                    zeroDiagonalPotentialMoves[0][1]++;
                }
                if ((row + column) == (field->getSize() - 1)) {
                    crossDiagonalPotentialMoves[1][0] = 0;

                    crossDiagonalPotentialMoves[1][1] = crossDiagonalPotentialMoves[1][1] > 0 ? --crossDiagonalPotentialMoves[1][1] : 0;
                    zeroDiagonalPotentialMoves[1][1]++;
                }
            }
        }
    }
}

GameResult GameResultCalculator::makeResult(const bool &crossHasMoves, const bool &zeroHasMoves, const bool &crossWon, const bool &zeroWon)
{
    auto result = GameResult();

    if (crossWon) {
        result.winner = PlayerSide::USE_CROSS;
        result.result = GameResult::WIN;

        return result;
    }
    if (zeroWon) {
        result.winner = PlayerSide::USE_ZERO;
        result.result = GameResult::WIN;

        return result;
    }

    if (!zeroHasMoves && !crossHasMoves) {
        result.result = GameResult::DRAW;
        return result;
    }

    result.result = GameResult::HAS_MOVES;

    return result;
}

void GameResultCalculator::calculateResultValues(std::map<size_t, size_t[2]> &array, size_t fieldSize, bool &won, bool &hasMoves)
{
    for (size_t i = 0; i < array.size(); i++) {
        if (array[i][0] > 0) {
            hasMoves = true;
        }
        if (array[i][1] == fieldSize) {
            won = true;
        }
    }
}

GameResult GameResultCalculator::getResult(Field *field)
{
    std::map<size_t, size_t[2]> crossRowPotentialMoves = {};
    std::map<size_t, size_t[2]> crossColumnPotentialMoves = {};
    std::map<size_t, size_t[2]> crossDiagonalPotentialMoves = {};
    std::map<size_t, size_t[2]> zeroRowPotentialMoves = {};
    std::map<size_t, size_t[2]> zeroColumnPotentialMoves = {};
    std::map<size_t, size_t[2]> zeroDiagonalPotentialMoves = {};

    initCalculationArrays(
        field->getSize(),
        crossRowPotentialMoves,
        crossColumnPotentialMoves,
        crossDiagonalPotentialMoves,
        zeroRowPotentialMoves,
        zeroColumnPotentialMoves,
        zeroDiagonalPotentialMoves
    );

    calculateArrays(
        field,
        crossRowPotentialMoves,
        crossColumnPotentialMoves,
        crossDiagonalPotentialMoves,
        zeroRowPotentialMoves,
        zeroColumnPotentialMoves,
        zeroDiagonalPotentialMoves
    );

    bool crossHasMoves = false, zeroHasMoves = false, crossWon = false, zeroWon = false;

    calculateResultValues(crossRowPotentialMoves, field->getSize(), crossWon, crossHasMoves);
    calculateResultValues(crossColumnPotentialMoves, field->getSize(), crossWon, crossHasMoves);
    calculateResultValues(crossDiagonalPotentialMoves, field->getSize(), crossWon, crossHasMoves);

    calculateResultValues(zeroRowPotentialMoves, field->getSize(), zeroWon, zeroHasMoves);
    calculateResultValues(zeroColumnPotentialMoves, field->getSize(), zeroWon, zeroHasMoves);
    calculateResultValues(zeroDiagonalPotentialMoves, field->getSize(), zeroWon, zeroHasMoves);

    return makeResult(crossHasMoves, zeroHasMoves, crossWon, zeroWon);
}

void GameResultCalculator::showArray(const std::string &arrayName, std::map<size_t, size_t[2]> &array)
{
    std::cout << arrayName << std::endl;

    for (size_t i = 0; i < array.size(); i++) {
        std::cout << i << ": " << array[i][0] << " " << array[i][1] << std::endl;
    }
}
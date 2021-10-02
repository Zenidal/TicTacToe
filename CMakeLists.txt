cmake_minimum_required(VERSION 3.20)

project(TicTacToe)

set(CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME} main.cpp Core/Includes/CellPosition.h Core/Includes/CellValues.h Core/Includes/Field.h Core/Includes/FieldRender.h Core/Includes/Game.h Core/Includes/GameEngine.h Core/Includes/GameResult.h Core/Includes/GameResultCalculator.h Core/Includes/GameStatus.h Core/Includes/GameStatuses.h Core/Includes/InvalidCellValueException.h Core/Includes/MoveException.h Core/Includes/MoveExceptionReasons.h Core/Includes/Player.h Core/Includes/PlayerSide.h Core/Field/CellPosition.cpp Core/Field/Field.cpp Core/Field/FieldRender.cpp Core/Field/InvalidCellValueException.cpp Core/Game/Game.cpp Core/Game/GameEngine.cpp Core/Game/GameResultCalculator.cpp Core/Game/GameStatus.cpp Core/Game/MoveException.cpp Core/Player/Player.cpp)
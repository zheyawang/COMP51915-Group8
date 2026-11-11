#include "game_logic.h"

// Check whether the input contains two valid coordinates
bool readValidMove(std::istream& input, int& row, int& col) {

    // Check whether two integers can be read
    if (!(input >> row >> col)) {
        return false;
    }

    // Check whether both coordinates are within the board
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        return false;
    }

    return true;
}


// Check whether a position is empty
bool isPositionEmpty(int board[3][3], int row, int col) {

    // Check whether the coordinates are within the board
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        return false;
    }

    // A position is empty if its value is 0
    return board[row][col] == 0;
}

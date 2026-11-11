#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include <istream>

// Check whether the input contains two valid coordinates
bool readValidMove(std::istream& input, int& row, int& col);

// Check whether a position is empty
bool isPositionEmpty(int board[3][3], int row, int col);

#endif

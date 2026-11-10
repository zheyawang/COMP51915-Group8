#include <gtest/gtest.h>
#include "parse_board.h"


// Test 1: Player 1 wins horizontally
TEST(ParseBoardTest, Player1WinsHorizontally) {
    int board[3][3] = {
        {1, 1, 1},
        {2, 0, 0},
        {0, 2, 0}
    };

    EXPECT_EQ(1, parseBoard(board));
}


// Test 2: Player 2 wins vertically
TEST(ParseBoardTest, Player2WinsVertically) {
    int board[3][3] = {
        {1, 2, 1},
        {0, 2, 0},
        {1, 2, 0}
    };

    EXPECT_EQ(2, parseBoard(board));
}


// Test 3: Player 1 wins diagonally (top-left to bottom-right)
TEST(ParseBoardTest, Player1WinsDiagonally) {
    int board[3][3] = {
        {1, 2, 0},
        {2, 1, 0},
        {0, 0, 1}
    };

    EXPECT_EQ(1, parseBoard(board));
}


// Test 4: Player 2 wins diagonally (top-right to bottom-left)
TEST(ParseBoardTest, Player2WinsDiagonally) {
    int board[3][3] = {
        {1, 0, 2},
        {1, 2, 0},
        {2, 1, 1}
    };

    EXPECT_EQ(2, parseBoard(board));
}


// Test 5: Full board without winner
TEST(ParseBoardTest, FullBoardWithoutWinnerReturnsZero) {
    int board[3][3] = {
        {1, 2, 1},
        {1, 2, 2},
        {2, 1, 1}
    };

    EXPECT_EQ(0, parseBoard(board));
}

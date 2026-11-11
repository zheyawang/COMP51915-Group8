#include <gtest/gtest.h>
#include <sstream>
#include "game_logic.h"

// Test 1: Valid input
TEST(GameLogicTest, AcceptsValidCoordinates) {
    std::stringstream input("0 1");

    int row, col;

    EXPECT_TRUE(readValidMove(input, row, col));
    EXPECT_EQ(0, row);
    EXPECT_EQ(1, col);
}

// Test 2: Out-of-range coordinates
TEST(GameLogicTest, RejectsOutOfRangeCoordinates) {
    std::stringstream input("0 3");

    int row, col;

    EXPECT_FALSE(readValidMove(input, row, col));
}

// Test 3: Non-numeric input
TEST(GameLogicTest, RejectsNonNumericInput) {
    std::stringstream input("a b");

    int row, col;

    EXPECT_FALSE(readValidMove(input, row, col));
}

// Test 4: Rejects an occupied position
TEST(GameLogicTest, RejectsOccupiedPosition) {
    int board[3][3] = {
        {1, 0, 0},
        {0, 2, 0},
        {0, 0, 0}
    };

    EXPECT_FALSE(isPositionEmpty(board, 0, 0));
}

// Test 5: Accepts an empty position
TEST(GameLogicTest, AcceptsEmptyPosition) {
    int board[3][3] = {
        {1, 0, 0},
        {0, 2, 0},
        {0, 0, 0}
    };

    EXPECT_TRUE(isPositionEmpty(board, 0, 1));
}

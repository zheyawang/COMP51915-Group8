#include "parse_board.h"

int parseBoard(int board[3][3]) {
    for (int row = 0; row < 3; ++row) {
        const int player = board[row][0];

        if (player != 0 &&
            board[row][1] == player &&
            board[row][2] == player) {
            return player;
        }
    }

    for (int column = 0; column < 3; ++column) {
        const int player = board[0][column];

        if (player != 0 &&
            board[1][column] == player &&
            board[2][column] == player) {
            return player;
        }
    }

    const int centre = board[1][1];

    if (centre != 0 &&
        board[0][0] == centre &&
        board[2][2] == centre) {
        return centre;
    }

    if (centre != 0 &&
        board[0][2] == centre &&
        board[2][0] == centre) {
        return centre;
    }

    return 0;
}
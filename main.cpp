#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "parse_board.h"
#include <string>
#include <sstream>

const int M = 3;  // You can change this for your specific game!
const int N = 3;  // You can change this for your specific game!

void initBoard(int board[M][N], int M, int N) {
  for (int m = 0; m < M; m++) {
    for (int n = 0; n < N; n++) {
      board[m][n] = 0;
    }
  }
}


void gameLoop(int board[M][N], bool cont, int players, int M, int N) {
    while (cont) {
        for (int p = 1; p <= players; ++p) {
            int m, n;

            while (true) {
                std::cout << "Player " << p
                          << " place (row column, 0-2): ";

                std::string line;
                if (!std::getline(std::cin >> std::ws, line)) {
                    return;
                }

                std::istringstream input(line);
                std::string extra;

                if (!(input >> m >> n) || (input >> extra)) {
                    std::cout << "Enter two integers from 0 to 2."
                              << std::endl;
                    continue;
                }

                if (m < 0 || m >= M || n < 0 || n >= N) {
                    std::cout << "Invalid position! Use 0, 1 or 2."
                              << std::endl;
                    continue;
                }

                if (board[m][n] != 0) {
                    std::cout << "That position is already occupied!"
                              << std::endl;
                    continue;
                }

                board[m][n] = p;
                std::cout << p << " at (" << m << ", " << n << ")."
                          << std::endl;
                break;
            }

            const int winner = parseBoard(board);

            if (winner != 0) {
                std::cout << "Player " << winner << " has won!"
                          << std::endl;
                return;
            }

            bool full = true;

            for (int row = 0; row < M; ++row) {
                for (int column = 0; column < N; ++column) {
                    if (board[row][column] == 0) {
                        full = false;
                    }
                }
            }

            if (full) {
                std::cout << "It's a draw!" << std::endl;
                return;
            }
        }
    }
}

int main(void) {
  int P = 2;
  bool cont = true;

  std::cout << "Tic-tac-toe! Player 1 is ×, Player 2 is ○." << std::endl;

  int board[M][N];
  initBoard(board, M, N);
  gameLoop(board, cont, P, M, N);

  return EXIT_SUCCESS;
}

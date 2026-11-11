#include <iostream>
#include <cstdio>
#include <cstdlib>

const int M = 3;  // You can change this for your specific game!
const int N = 3;  // You can change this for your specific game!

void initBoard(int board[M][N], int M, int N) {
  for (int m = 0; m < M; m++) {
    for (int n = 0; n < N; n++) {
      board[m][n] = 0;
    }
  }
}

int parseBoard(int board[M][N]) {
  for (int row = 0; row < M; ++row) {
    const int player = board[row][0];
    if (player != 0 && board[row][1] == player && board[row][2] == player) {
      return player;
    }
  }

  for (int column = 0; column < N; ++column) {
    const int player = board[0][column];
    if (player != 0 && board[1][column] == player && board[2][column] == player) {
      return player;
    }
  }

  const int centre = board[1][1];
  if (centre != 0 && board[0][0] == centre && board[2][2] == centre) {
    return centre;
  }
  if (centre != 0 && board[0][2] == centre && board[2][0] == centre) {
    return centre;
  }

  return 0;
}

void gameLoop(int board[M][N], bool cont, int players, int M, int N) {
  int winner;
  int m, n;
  do {
    for (int p = 1; p <= players; ++p) {
      std::cout << "Player " << p << " place:";
      std::cin >> m >> n;
      if (board[m][n] == 0) {
        std::cout << p << " at (" << m << ", " << n << ")." << std::endl;
        board[m][n] = p;
      } else {
        std::cout << "Illegal move!" << std::endl;
      }
    }
    winner = parseBoard(board);
    if (winner != 0) {
      std::cout << "Player " << winner << " has won!" << std::endl;
      cont = false;
    }
  } while (cont);
}

int main(void) {
  int P;
  bool cont = true;

  std::cout << "Initialising game... How many players?";
    std::cin >> P;

  int board[M][N];
  initBoard(board, M, N);
  gameLoop(board, cont, P, M, N);

  return EXIT_SUCCESS;
}

#include "computer.h"

#include <cstdlib>

void computerPlayer(int grid[3][3]) {
    int emptySquares = 0;
    int *ptrEmptySqr{};
    int playerSquares = 0;
    int playerSqrPos[2]{};

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[i][j] == 0) {
                ++emptySquares;
                ptrEmptySqr = &grid[i][j];
            } else if (grid[i][j] == 1) {
                ++playerSquares;
                playerSqrPos[0] = i;
                playerSqrPos[1] = j;
            }
        }
    }

    if (emptySquares == 1) {
        *ptrEmptySqr = 2;
        return;
    }

    if (playerSquares == 1) {
        if (grid[1][1] == 0) {
            grid[1][1] = 2;
            return;
        } else {
            switch (rand() % 2) {
                case 0: {
                    for (int i = 0; i < 3; ++i) {
                        if (grid[playerSqrPos[0]][i] == 0) {
                            grid[playerSqrPos[0]][i] = 2;
                            return;
                        }
                    }
                } break;
                case 1: {
                    for (int i = 0; i < 3; ++i) {
                        if (grid[i][playerSqrPos[1]] == 0) {
                            grid[i][playerSqrPos[1]] = 2;
                            return;
                        }
                    }
                } break;
            }
        }
    } else {
        // check if there's a winning move
        if (checkWinningMove(grid, 2)) {
            return;
        }
        // check if there's a move to prevent the other player to win
        if (checkWinningMove(grid, 1)) {
            return;
        }

        // if no winning or saving move just use an empty one.
	// i should check for diagonals that have the column and the row with some value
	// because it's easy to win starting with 4 or 6 then going 2 
        *ptrEmptySqr = 2;
        return;
    }
}

bool checkWinningMove(int grid[3][3], int player) {
    for (int i = 0; i < 3; ++i) {
        int rowsWinning = 0;
        int columnsWinning = 0;

        // Check if there are a row or a column with two of the same value
        for (int j = 0; j < 3; ++j) {
            if (grid[i][j] == player) {
                ++rowsWinning;
            }

            if (grid[j][i] == player) {
                ++columnsWinning;
            }
        }

        if (rowsWinning == 2) {
            for (int x = 0; x < 3; ++x) {
                if (grid[i][x] == 0) {
                    grid[i][x] = 2;
                    return true;
                }
            }
        }

        if (columnsWinning == 2) {
            for (int x = 0; x < 3; ++x) {
                if (grid[x][i] == 0) {
                    grid[x][i] = 2;
                    return true;
                }
            }
        }

        // Check diagonals
        int diagonalWin = 0;
        for (int x = 0; x < 3; ++x) {
            if (grid[x][x] == player) {
                ++diagonalWin;
            }
        }

        if (diagonalWin == 2) {
            for (int x = 0; x < 3; ++x) {
                if (grid[x][x] == 0) {
                    grid[x][x] = 2;
                    return true;
                }
            }
        }

        diagonalWin = 0;
        int *diagonal[3] = {&grid[0][2], &grid[1][1], &grid[2][0]};

        for (int x = 0; x < 3; ++x) {
            if (*diagonal[x] == player) {
                ++diagonalWin;
            }
        }

        if (diagonalWin == 2) {
            for (int x = 0; x < 3; ++x) {
                if (*diagonal[x] == 0) {
                    *diagonal[x] = 2;
                    return true;
                }
            }
        }
    }

    return false;
}

#include "computer.h"

#include <cstdlib>

void computerPlayer(int grid[3][3], int playerValue, int computerValue) {
    int emptySquares = 0;
    int *ptrEmptySqr{};
    int playerSquares = 0;
    int playerSqrPos[2]{};

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[i][j] == 0) {
                ++emptySquares;
                ptrEmptySqr = &grid[i][j];
            } else if (grid[i][j] == playerValue) {
                ++playerSquares;
                playerSqrPos[0] = i;
                playerSqrPos[1] = j;
            }
        }
    }

    if (emptySquares == 1) {
        *ptrEmptySqr = computerValue;
        return;
    }

    if (playerSquares == 1) {
        if (grid[1][1] == 0) {
            grid[1][1] = computerValue;
            return;
        } else {
            switch (rand() % 2) {
                case 0: {
                    for (int i = 0; i < 3; ++i) {
                        if (grid[playerSqrPos[0]][i] == 0) {
                            grid[playerSqrPos[0]][i] = computerValue;
                            return;
                        }
                    }
                } break;
                case 1: {
                    for (int i = 0; i < 3; ++i) {
                        if (grid[i][playerSqrPos[1]] == 0) {
                            grid[i][playerSqrPos[1]] = computerValue;
                            return;
                        }
                    }
                } break;
            }
        }
    } else {
        // check if there's a winning move
        if (checkWinningMove(grid, computerValue, computerValue)) {
            return;
        }
        // check if there's a move to prevent the other player to win
        if (checkWinningMove(grid, playerValue, computerValue)) {
            return;
        }

        // if no winning or saving move just use an empty one.
        *ptrEmptySqr = 2;
        return;
    }
}

bool checkWinningMove(int grid[3][3], int playerValue, int computerValue) {
    for (int i = 0; i < 3; ++i) {
        int rowsWinning = 0;
        int columnsWinning = 0;

        // Check if there are a row or a column with two of the same value
        for (int j = 0; j < 3; ++j) {
            if (grid[i][j] == playerValue) {
                ++rowsWinning;
            }

            if (grid[j][i] == playerValue) {
                ++columnsWinning;
            }
        }

        if (rowsWinning == 2) {
            for (int x = 0; x < 3; ++x) {
                if (grid[i][x] == 0) {
                    grid[i][x] = computerValue;
                    return true;
                }
            }
        }

        if (columnsWinning == 2) {
            for (int x = 0; x < 3; ++x) {
                if (grid[x][i] == 0) {
                    grid[x][i] = computerValue;
                    return true;
                }
            }
        }

        // Check diagonals
        int diagonalWin = 0;
        for (int x = 0; x < 3; ++x) {
            if (grid[x][x] == playerValue) {
                ++diagonalWin;
            }
        }

        if (diagonalWin == 2) {
            for (int x = 0; x < 3; ++x) {
                if (grid[x][x] == 0) {
                    grid[x][x] = computerValue;
                    return true;
                }
            }
        }

        diagonalWin = 0;
        int *diagonal[3] = {&grid[0][2], &grid[1][1], &grid[2][0]};

        for (int x = 0; x < 3; ++x) {
            if (*diagonal[x] == playerValue) {
                ++diagonalWin;
            }
        }

        if (diagonalWin == 2) {
            for (int x = 0; x < 3; ++x) {
                if (*diagonal[x] == 0) {
                    *diagonal[x] = computerValue;
                    return true;
                }
            }
        }
    }

    return false;
}

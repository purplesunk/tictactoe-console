#include "tictactoe.h"

#include <iostream>

#include "utils.h"

void drawGrid(int grid[3][3]) {
    for (int i = 0; i < 3; ++i) {
        std::cout << "-------------\n";
        std::cout << "| ";
        for (int j = 0; j < 3; ++j) {
            if (grid[i][j] == 1) {
                std::cout << "X | ";
            } else if (grid[i][j] == 2) {
                std::cout << "O | ";
            } else {
                std::cout << (i * 3) + (j + 1) << " | ";
            }
        }
        std::cout << "\n";
    }
    std::cout << "-------------\n";
}

void drawValues(int grid[3][3]) {
    for (int i = 0; i < 3; ++i) {
        std::cout << "-------------\n";
        std::cout << "| ";
        for (int j = 0; j < 3; ++j) {
            std::cout << grid[i][j] << " | ";
        }
        std::cout << "\n";
    }
    std::cout << "-------------\n";
}

void setSquare(int grid[3][3], int player) {
    while (true) {
        std::cout << "Turn Player " << player << ":\n";
        int square = getInteger("Choose a square: ");
        if (square < 1 || square > 9) {
            std::cout << "Not a valid square.\n";
        } else if (grid[square / 3][(square % 3) - 1] == 0) {
            grid[square / 3][square % 3 - 1] = player;
            return;
        } else {
            std::cout << "Square already taken.\n";
        }
    }
}

int checkWinner(int grid[3][3]) {
    for (int i = 0; i < 3; ++i) {
        int row = 1;
        int column = 1;

        // They will be only 0, 1 or 2.
        int rowBefore = -1;
        int columnBefore = -1;

        for (int j = 0; j < 3; ++j) {
            // Check row
            if (grid[i][j] == rowBefore) {
                ++row;
            }
            rowBefore = grid[i][j];
            if (row == 3) {
                return rowBefore;
            }

            // Check column
            if (grid[j][i] == columnBefore) {
                ++column;
            }
            columnBefore = grid[j][i];
            if (column == 3) {
                return columnBefore;
            }
        }
    }

    // checking diagonals
    if ((grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) || (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0])) {
        return grid[1][1];
    } else {
        // checking for a draw
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (grid[i][j] == 0) {
                    return 0;  // no one win and there are possible moves to do.
                }
            }
        }
        return 3;  // it means they draw
    }
}

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "computer.h"
#include "tictactoe.h"
#include "utils.h"

void playComputer();
void twoPlayer();

int main() {
    srand(time(NULL));

    int option = 0;
    while (true) {
        clearConsole();
        std::cout << "----------------------\n";
        std::cout << "    TIC TAC TOE\n";
        std::cout << "----------------------\n";
        std::cout << "1. PLAY VS COMPUTER\n";
        std::cout << "2. TWO PLAYER\n";
        std::cout << "0. EXIT\n";
        std::cout << "----------------------\n";

        option = getInteger("OPTION: ");

        switch (option) {
            case 1:
                playComputer();
                break;
            case 2:
                twoPlayer();
                break;
            case 0:
                return 0;
                break;
        }
        pause();
    }
}

void twoPlayer() {
    // When the grid has a 0 it's empty
    // 1 it has an X.
    // 2 it has an O.
    int grid[3][3]{0};

    int turn = 0;
    int player = 0;

    while (true) {
        clearConsole();
        drawGrid(grid);

        player = (turn % 2) + 1;
        setSquare(grid, player);

        switch (checkWinner(grid)) {
            case 1:
            case 2:
                drawGrid(grid);
                std::cout << "Player " << player << " won!\n";
                return;
                break;
            case 3:
                drawGrid(grid);
                std::cout << "Draw.\n";
                return;
                break;
        }

        ++turn;
    }
}

void playComputer() {
    // When the grid has a 0 it's empty
    // 1 it has an X.
    // 2 it has an O.
    int grid[3][3]{0};

    int turn = 0;
    int winner = 0;

    while (true) {
        clearConsole();
        drawGrid(grid);

        if (turn % 2 == 0) {
            setSquare(grid, 1);
        } else {
            computerPlayer(grid);
        }

        winner = checkWinner(grid);
        switch (winner) {
            case 1:
            case 2:
                drawGrid(grid);
                std::cout << "Player " << winner << " won!\n";
                return;
                break;
            case 3:
                drawGrid(grid);
                std::cout << "Draw.\n";
                return;
                break;
        }

        ++turn;
    }
}
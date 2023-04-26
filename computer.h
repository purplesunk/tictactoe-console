#ifndef COMPUTER_H_INCLUDED
#define COMPUTER_H_INCLUDED

void computerPlayer(int grid[3][3], int playerValue = 1, int computerValue = 2);
bool checkWinningMove(int grid[3][3], int playerValue, int computerValue = 2);

#endif
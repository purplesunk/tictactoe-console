#ifndef TICTACTOE_H_INCLUDED
#define TICTACTOE_H_INCLUDED

void drawGrid(int grid[3][3]);
void drawValues(int grid[3][3]);
void setSquare(int grid[3][3], int player);
int checkWinner(int grid[3][3]);

#endif
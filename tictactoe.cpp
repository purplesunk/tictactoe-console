#include <iostream>
#include <limits>

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
   }
   std::cout << "\n";
   std::cout << "-------------\n";
}

int askSquare() {
   int square{};
   std::cout << "\nChoose a square: ";
   std::cin >> square;

   while (!std::cin) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Choose a square: ";
      std::cin >> square;
   }

   return square;
}

void setSquare(int grid[3][3], int player) {
   while (true) {
      std::cout << "Turn Player " << player << ":";
      int square = askSquare();
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
      drawValues(grid);
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
      std::cout << "We draw \n";
      return 3;  // it means they draw
   }
}

int main() {
   // When the grid has a 0 it's empty
   // 1 it has an X.
   // 2 it has an O.
   int grid[3][3]{0};

   int turn = 0;

   while (true) {
      int player = (turn % 2) + 1;
      drawGrid(grid);

      setSquare(grid, player);

      switch (checkWinner(grid)) {
         case 1:
         case 2:
            drawGrid(grid);
            std::cout << "Player " << player << " won!\n";
            return 0;
            break;
         case 3:
            drawGrid(grid);
            std::cout << "Draw.\n";
            return 0;
            break;
      }

      ++turn;
   }
}
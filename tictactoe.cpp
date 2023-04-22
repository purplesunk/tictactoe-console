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

void setSquare(int grid[3][3], int square, int player) {
   if (square < 1 || square > 9) {
      std::cout << "Not a valid square.\n";
   } else {
      grid[square / 3][square % 3 - 1] = player;
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

   return 0;
}

int main() {
   // When the grid has a 0 it's empty
   // 1 it has an X.
   // 2 it has an O.
   int grid[3][3]{0};

   while (true) {
      drawGrid(grid);

      int square = askSquare();

      setSquare(grid, square, 1);

      if (checkWinner(grid) != 0) {
         drawGrid(grid);
         std::cout << "Wow someone won\n";
         return 0;
      }
   }
}
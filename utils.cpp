#include "utils.h"

#include <iostream>
#include <limits>

void clearConsole() {
    std::cout << "\033[2J\033[1;1H";
}

int getInteger(const char *question) {
    int number;
    std::cout << question;
    std::cin >> number;

    while (!std::cin) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << question;
        std::cin >> number;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return number;
}

void pause() {
    std::cout << "Press enter to continue.\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

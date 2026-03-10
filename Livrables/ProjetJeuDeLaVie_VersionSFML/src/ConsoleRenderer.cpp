#include "../include/ConsoleRenderer.hpp"
#include <iostream>

/**
 * @brief Prints the grid.
 * 
 * Uses ANSI escape codes to clear the screen and reset cursor position.
 */
void ConsoleRenderer::printGrid(const Grid& grid) {
    std::cout << "\x1B[2J\x1B[H";

    for (int r = 0; r < grid.getRows(); ++r) {
        for (int c = 0; c < grid.getCols(); ++c) {
            std::cout << (grid.getCell(r, c).isAlive() ? "O" : ".");
        }
        std::cout << "\n";
    }
}

/**
 * @brief Prints statistics.
 */
void ConsoleRenderer::printStats(int iteration, int aliveCount) {
    std::cout << "Iteration : " << iteration << "\n";
    std::cout << "Population : " << aliveCount << "\n";
    std::cout << "----------------------\n";
}

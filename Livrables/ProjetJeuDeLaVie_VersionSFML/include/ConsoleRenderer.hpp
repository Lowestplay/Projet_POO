#pragma once
#include "Grid.hpp"

/**
 * @brief Handles text-based rendering of the game in the console.
 * 
 * Useful for debugging or running the game in a non-graphical environment.
 */
class ConsoleRenderer {
public:
    /**
     * @brief Prints the grid to the console.
     * 
     * Uses 'O' for alive cells and '.' for dead cells.
     * Clears the console before printing.
     * 
     * @param grid The grid to print.
     */
    static void printGrid(const Grid& grid);

    /**
     * @brief Prints game statistics to the console.
     * 
     * @param iteration Current generation number.
     * @param aliveCount Number of alive cells.
     */
    static void printStats(int iteration, int aliveCount);
};

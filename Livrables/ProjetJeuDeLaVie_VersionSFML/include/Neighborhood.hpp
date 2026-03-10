#pragma once
#include "../include/Grid.hpp"

/**
 * @brief Utility class for calculating cell neighbors.
 */
class Neighborhood {
public:
    /**
     * @brief Counts the number of alive neighbors for a specific cell.
     * 
     * Checks the 8 surrounding cells (Moore neighborhood).
     * 
     * @param grid The grid containing the cells.
     * @param r Row index of the center cell.
     * @param c Column index of the center cell.
     * @param toroidal If true, wraps edges (e.g., left neighbor of col 0 is col max).
     * @return The number of alive neighbors (0-8).
     */
    static int countNeighbors(const Grid& grid, int r, int c, bool toroidal);
};

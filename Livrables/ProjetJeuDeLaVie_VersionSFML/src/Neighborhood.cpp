#include "../include/Neighborhood.hpp"

/**
 * @brief Counts neighbors.
 * 
 * Iterates through the 3x3 block centered on (r, c).
 * Skips the center cell itself.
 * Handles toroidal wrapping if enabled.
 */
int Neighborhood::countNeighbors(const Grid& grid, int r, int c, bool toroidal) {
    int count = 0;
    int rows = grid.getRows();
    int cols = grid.getCols();

    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue;

            int nr = r + i;
            int nc = c + j;

            if (toroidal) {
                nr = (nr % rows + rows) % rows;
                nc = (nc % cols + cols) % cols;
            }

            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                if (grid.getCell(nr, nc).isAlive()) {
                    count++;
                }
            }
        }
    }
    return count;
}

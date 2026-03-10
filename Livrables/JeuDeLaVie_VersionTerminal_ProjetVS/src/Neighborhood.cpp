#include "../include/Neighborhood.hpp"

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
                // Formule robuste : ((a % n) + n) % n gère correctement les nombres négatifs
                nr = (nr % rows + rows) % rows;
                nc = (nc % cols + cols) % cols;
            }

            // Vérification des bornes (utile si NON torique, toujours vrai si torique)
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                if (grid.getCell(nr, nc).isAlive()) {
                    count++;
                }
            }
        }
    }
    return count;
}
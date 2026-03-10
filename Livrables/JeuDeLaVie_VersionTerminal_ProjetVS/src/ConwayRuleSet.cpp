#include "../include/ConwayRuleSet.hpp"
#include "../include/Neighborhood.hpp"

void ConwayRuleSet::applyRules(const Grid& current, Grid& next, bool toroidal) {
    // Redimensionne la grille de destination si nécessaire
    if (next.getRows() != current.getRows() || next.getCols() != current.getCols()) {
        next = Grid(current.getRows(), current.getCols());
    }

    for (int r = 0; r < current.getRows(); ++r) {
        for (int c = 0; c < current.getCols(); ++c) {
            int neighbors = Neighborhood::countNeighbors(current, r, c, toroidal);
            bool isAlive = current.getCell(r, c).isAlive();

            // Règles de Conway
            // 1. Morte avec exactement 3 voisines -> Vivante
            if (!isAlive && neighbors == 3) {
                next.setCell(r, c, true);
            }
            // 2. Vivante avec 2 ou 3 voisines -> Reste vivante, sinon meurt
            else if (isAlive && (neighbors == 2 || neighbors == 3)) {
                next.setCell(r, c, true);
            }
            else {
                next.setCell(r, c, false);
            }
        }
    }
}

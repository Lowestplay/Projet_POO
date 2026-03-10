#include "../include/ConwayRuleSet.hpp"
#include "../include/Neighborhood.hpp"

/**
 * @brief Applies Conway's rules to the grid.
 * 
 * Iterates over every cell, counts its neighbors, and determines its next state.
 * Resizes the destination grid if dimensions do not match.
 */
void ConwayRuleSet::applyRules(const Grid& current, Grid& next, bool toroidal) {
    if (next.getRows() != current.getRows() || next.getCols() != current.getCols()) {
        next = Grid(current.getRows(), current.getCols());
    }

    for (int r = 0; r < current.getRows(); ++r) {
        for (int c = 0; c < current.getCols(); ++c) {
            int neighbors = Neighborhood::countNeighbors(current, r, c, toroidal);
            bool isAlive = current.getCell(r, c).isAlive();

            if (!isAlive && neighbors == 3) {
                next.setCell(r, c, true);
            }
            else if (isAlive && (neighbors == 2 || neighbors == 3)) {
                next.setCell(r, c, true);
            }
            else {
                next.setCell(r, c, false);
            }
        }
    }
}

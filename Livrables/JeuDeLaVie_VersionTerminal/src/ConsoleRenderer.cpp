#include "../include/ConsoleRenderer.hpp"
#include <iostream>

void ConsoleRenderer::printGrid(const Grid& grid) {
    // On efface la console (approche simple ANSI)
    std::cout << "\x1B[2J\x1B[H";

    for (int r = 0; r < grid.getRows(); ++r) {
        for (int c = 0; c < grid.getCols(); ++c) {
            // Affichage visuel demandé
            std::cout << (grid.getCell(r, c).isAlive() ? "O" : ".");
        }
        std::cout << "\n";
    }
}

void ConsoleRenderer::printStats(int iteration, int aliveCount) {
    std::cout << "Iteration : " << iteration << "\n";
    std::cout << "Population : " << aliveCount << "\n";
    std::cout << "----------------------\n";
}

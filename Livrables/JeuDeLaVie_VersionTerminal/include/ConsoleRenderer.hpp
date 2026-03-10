#pragma once
#include "Grid.hpp"

class ConsoleRenderer {
public:
    // Affiche la grille dans la console.
    static void printGrid(const Grid& grid);

    // Affiche les statistiques courantes.
    static void printStats(int iteration, int aliveCount);
};

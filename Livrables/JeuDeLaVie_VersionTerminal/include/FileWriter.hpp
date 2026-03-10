#pragma once
#include "../include/Grid.hpp"
#include <string>

class FileWriter {
public:
    // Écrit l'état de la grille dans un fichier.
    static void write(const Grid& grid, const std::string& folder, int iteration);
};

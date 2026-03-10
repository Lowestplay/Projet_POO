#include "../include/FileLoader.hpp"
#include <fstream>
#include <stdexcept>

/**
 * @brief Loads grid from file.
 * 
 * Reads dimensions then cell states (0 or 1).
 */
Grid FileLoader::loadFromFile(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        throw std::runtime_error("Impossible d'ouvrir le fichier : " + path);
    }

    int rows, cols;
    if (!(file >> rows >> cols)) {
        throw std::runtime_error("En-tete de fichier invalide");
    }

    Grid grid(rows, cols);
    int state;
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (file >> state) {
                grid.setCell(r, c, state == 1);
            }
        }
    }
    return grid;
}

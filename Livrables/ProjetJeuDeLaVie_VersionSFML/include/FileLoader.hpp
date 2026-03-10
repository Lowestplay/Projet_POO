#pragma once
#include "../include/Grid.hpp"
#include <string>

/**
 * @brief Utility class for loading grids from files.
 */
class FileLoader {
public:
    /**
     * @brief Loads a grid from a text file.
     * 
     * The file format is expected to be:
     * rows cols
     * cell_state cell_state ...
     * 
     * @param path Path to the file.
     * @return The loaded Grid object.
     * @throws std::runtime_error if the file cannot be opened or format is invalid.
     */
    static Grid loadFromFile(const std::string& path);
};

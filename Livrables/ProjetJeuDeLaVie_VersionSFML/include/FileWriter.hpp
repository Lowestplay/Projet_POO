#pragma once
#include "../include/Grid.hpp"
#include <string>

/**
 * @brief Utility class for saving grids to files.
 */
class FileWriter {
public:
    /**
     * @brief Writes the grid state to a file.
     * 
     * Creates the output folder if it doesn't exist.
     * Filename format: iteration_XXX.txt
     * 
     * @param grid The grid to save.
     * @param folder The destination folder.
     * @param iteration The current iteration number (used for filename).
     */
    static void write(const Grid& grid, const std::string& folder, int iteration);
};

#pragma once
#include <string>

/**
 * @brief Configuration structure for the application.
 * 
 * Holds settings parsed from command line arguments or default values.
 */
struct Config {
    std::string filePath;       ///< Path to the initial grid file.
    int maxIterations = 100;    ///< Maximum number of iterations (for console mode).
    bool toroidal = false;      ///< Whether the grid is toroidal.
    std::string outputFolder;   ///< Folder to save output files.

    int stepMs = 100;           ///< Duration of a simulation step in milliseconds.
    int cellSize = 10;          ///< Size of a cell in pixels for rendering.

    /**
     * @brief Parses command line arguments.
     * 
     * Supported arguments:
     * --file=<path>
     * --max-iters=<int>
     * --toroidal=<0|1|true|false>
     * --step-ms=<int>
     * --cell-size=<int>
     * 
     * @param argc Argument count.
     * @param argv Argument values.
     */
    void parseArgs(int argc, char* argv[]);
};

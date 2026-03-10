#include "../include/Config.hpp"
#include <string>
#include <iostream>

/**
 * @brief Parses command line arguments.
 * 
 * Iterates through argv and sets the corresponding configuration members.
 * Handles string to integer conversion and boolean parsing.
 */
void Config::parseArgs(int argc, char* argv[]) {
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg.find("--file=") == 0) {
            filePath = arg.substr(7);
            outputFolder = filePath + "_out";
        }
        else if (arg.find("--max-iters=") == 0) {
            try { maxIterations = std::stoi(arg.substr(12)); }
            catch (...) {}
        }
        else if (arg.find("--toroidal=") == 0) {
            std::string val = arg.substr(11);
            toroidal = (val == "1" || val == "true");
        }
        else if (arg.find("--step-ms=") == 0) {
            try { stepMs = std::stoi(arg.substr(10)); }
            catch (...) {}
        }
        else if (arg.find("--cell-size=") == 0) {
            try { cellSize = std::stoi(arg.substr(12)); }
            catch (...) {}
        }
    }
}

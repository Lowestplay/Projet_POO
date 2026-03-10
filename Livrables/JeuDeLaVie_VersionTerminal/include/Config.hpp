#pragma once
#include <string>

struct Config {
    std::string filePath;
    int maxIterations = 100;
    bool toroidal = false;
    std::string outputFolder;

    // Parse les arguments de ligne de commande.
    void parseArgs(int argc, char* argv[]);
};

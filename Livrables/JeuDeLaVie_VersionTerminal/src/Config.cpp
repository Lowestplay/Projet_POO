#include "../include/Config.hpp"
#include <iostream>
#include <string>

void Config::parseArgs(int argc, char* argv[]) {
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        // Debug pour voir ce que le programme reçoit
        // std::cout << "Argument recu : " << arg << "\n"; 

        if (arg.find("--file=") == 0) {
            filePath = arg.substr(7);
            outputFolder = filePath + "_out";
        }
        else if (arg.find("--max-iters=") == 0) {
            try {
                maxIterations = std::stoi(arg.substr(12));
            }
            catch (...) { maxIterations = 100; }
        }
        else if (arg.find("--toroidal=") == 0) {
            // Si on trouve "1" après le =, c'est true.
            // On gère le cas où l'utilisateur met --toroidal=1 ou --toroidal=true
            std::string val = arg.substr(11);
            toroidal = (val == "1" || val == "true");
        }
    }
}

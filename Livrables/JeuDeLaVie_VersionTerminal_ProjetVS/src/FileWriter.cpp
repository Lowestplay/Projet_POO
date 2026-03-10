#include "../include/FileWriter.hpp"
#include <fstream>
#include <filesystem>
#include <sstream>
#include <iomanip>

namespace fs = std::filesystem;

void FileWriter::write(const Grid& grid, const std::string& folder, int iteration) {
    // Création du dossier si inexistant
    if (!fs::exists(folder)) {
        fs::create_directory(folder);
    }

    // Nommage : iteration_001.txt
    std::ostringstream filename;
    filename << folder << "/iteration_" << std::setw(3) << std::setfill('0') << iteration << ".txt";

    std::ofstream file(filename.str());
    if (file.is_open()) {
        file << grid.getRows() << " " << grid.getCols() << "\n";
        for (int r = 0; r < grid.getRows(); ++r) {
            for (int c = 0; c < grid.getCols(); ++c) {
                file << (grid.getCell(r, c).isAlive() ? "1" : "0") << (c == grid.getCols() - 1 ? "" : " ");
            }
            file << "\n";
        }
    }
}
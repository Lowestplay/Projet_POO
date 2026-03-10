#include "../include/FileWriter.hpp"
#include <fstream>
#include <filesystem>
#include <sstream>
#include <iomanip>

namespace fs = std::filesystem;

/**
 * @brief Writes grid to file.
 * 
 * Ensures directory exists.
 * Writes dimensions followed by cell states (1 for alive, 0 for dead).
 */
void FileWriter::write(const Grid& grid, const std::string& folder, int iteration) {
    if (!fs::exists(folder)) {
        fs::create_directory(folder);
    }

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

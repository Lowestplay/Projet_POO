#pragma once
#include "Cell.hpp"
#include <vector>

class Grid {
public:
    Grid() = default;
    Grid(int rows, int cols);

    [[nodiscard]] int getRows() const;
    [[nodiscard]] int getCols() const;
    [[nodiscard]] const Cell& getCell(int r, int c) const;

    void setCell(int r, int c, bool state);
    [[nodiscard]] Grid clone() const;
    [[nodiscard]] int countAlive() const;

    // Vérifie si deux grilles sont identiques (NOUVEAU)
    bool operator==(const Grid& other) const;

private:
    int m_rows = 0;
    int m_cols = 0;
    std::vector<Cell> m_cells;
};

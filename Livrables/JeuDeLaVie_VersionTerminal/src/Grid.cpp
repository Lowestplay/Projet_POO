#include "../include/Grid.hpp"

Grid::Grid(int rows, int cols) : m_rows(rows), m_cols(cols) {
    m_cells.resize(static_cast<size_t>(rows) * cols);
}

int Grid::getRows() const { return m_rows; }
int Grid::getCols() const { return m_cols; }

const Cell& Grid::getCell(int r, int c) const {
    return m_cells[static_cast<size_t>(r) * m_cols + c];
}

void Grid::setCell(int r, int c, bool state) {
    if (r >= 0 && r < m_rows && c >= 0 && c < m_cols) {
        m_cells[static_cast<size_t>(r) * m_cols + c].setAlive(state);
    }
}

Grid Grid::clone() const {
    return *this;
}

int Grid::countAlive() const {
    int count = 0;
    for (const auto& cell : m_cells) {
        if (cell.isAlive()) count++;
    }
    return count;
}

// NOUVEAU : Comparaison de grille
bool Grid::operator==(const Grid& other) const {
    if (m_rows != other.m_rows || m_cols != other.m_cols) {
        return false;
    }
    // Compare le contenu des vecteurs (grâce à Cell::operator==)
    return m_cells == other.m_cells;
}
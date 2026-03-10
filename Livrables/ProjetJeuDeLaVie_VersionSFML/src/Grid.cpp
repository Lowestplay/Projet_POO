#include "../include/Grid.hpp"

/**
 * @brief Constructor implementation.
 * 
 * Resizes the cell vector to fit the grid dimensions.
 */
Grid::Grid(int rows, int cols) : m_rows(rows), m_cols(cols) {
    m_cells.resize(static_cast<size_t>(rows) * cols);
}

/**
 * @brief Returns the number of rows.
 */
int Grid::getRows() const { return m_rows; }

/**
 * @brief Returns the number of columns.
 */
int Grid::getCols() const { return m_cols; }

/**
 * @brief Accesses a cell (read-only).
 * 
 * Uses 1D index calculation: index = r * cols + c.
 */
const Cell& Grid::getCell(int r, int c) const {
    return m_cells[static_cast<size_t>(r) * m_cols + c];
}

/**
 * @brief Sets a cell's state.
 * 
 * Performs bounds checking before setting the state.
 */
void Grid::setCell(int r, int c, bool state) {
    if (r >= 0 && r < m_rows && c >= 0 && c < m_cols) {
        m_cells[static_cast<size_t>(r) * m_cols + c].setAlive(state);
    }
}

/**
 * @brief Clones the grid.
 */
Grid Grid::clone() const {
    return *this;
}

/**
 * @brief Counts alive cells.
 * 
 * Iterates through all cells to count those that are alive.
 */
int Grid::countAlive() const {
    int count = 0;
    for (const auto& cell : m_cells) {
        if (cell.isAlive()) count++;
    }
    return count;
}

/**
 * @brief Equality operator implementation.
 * 
 * Compares dimensions and cell contents.
 */
bool Grid::operator==(const Grid& other) const {
    if (m_rows != other.m_rows || m_cols != other.m_cols) {
        return false;
    }
    return m_cells == other.m_cells;
}

/**
 * @brief Clears the grid.
 * 
 * Fills the cell vector with dead cells without reallocating memory.
 */
void Grid::clear() {
    std::fill(m_cells.begin(), m_cells.end(), Cell(false));
}

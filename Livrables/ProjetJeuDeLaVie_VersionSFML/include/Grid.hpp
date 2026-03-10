#pragma once
#include "Cell.hpp"
#include <vector>

/**
 * @brief Represents the game grid containing cells.
 * 
 * Manages the 2D grid of cells, providing accessors and modifiers for cell states,
 * as well as utility functions for grid manipulation (cloning, clearing, counting alive cells).
 */
class Grid {
public:
    /**
     * @brief Default constructor.
     */
    Grid() = default;

    /**
     * @brief Constructs a grid with specified dimensions.
     * 
     * @param rows Number of rows in the grid.
     * @param cols Number of columns in the grid.
     */
    Grid(int rows, int cols);

    /**
     * @brief Gets the number of rows.
     * 
     * @return The number of rows.
     */
    [[nodiscard]] int getRows() const;

    /**
     * @brief Gets the number of columns.
     * 
     * @return The number of columns.
     */
    [[nodiscard]] int getCols() const;

    /**
     * @brief Accesses a cell at a specific position (read-only).
     * 
     * @param r Row index.
     * @param c Column index.
     * @return A const reference to the cell.
     */
    [[nodiscard]] const Cell& getCell(int r, int c) const;

    /**
     * @brief Sets the state of a cell at a specific position.
     * 
     * @param r Row index.
     * @param c Column index.
     * @param state The new state (true for alive, false for dead).
     */
    void setCell(int r, int c, bool state);

    /**
     * @brief Creates a deep copy of the grid.
     * 
     * @return A new Grid object identical to this one.
     */
    [[nodiscard]] Grid clone() const;

    /**
     * @brief Counts the number of alive cells in the grid.
     * 
     * @return The count of alive cells.
     */
    [[nodiscard]] int countAlive() const;

    /**
     * @brief Equality operator.
     * 
     * Checks if two grids are identical in dimensions and cell states.
     * 
     * @param other The grid to compare with.
     * @return true if grids are identical, false otherwise.
     */
    bool operator==(const Grid& other) const;

    /**
     * @brief Clears the grid.
     * 
     * Sets all cells to dead state.
     */
    void clear();

private:
    int m_rows = 0;             ///< Number of rows.
    int m_cols = 0;             ///< Number of columns.
    std::vector<Cell> m_cells;  ///< Flat vector storing the cells.
};

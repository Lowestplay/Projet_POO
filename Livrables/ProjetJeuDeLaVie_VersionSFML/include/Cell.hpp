#pragma once

/**
 * @brief Represents a single cell in the grid.
 * 
 * A cell can be either alive or dead.
 */
class Cell {
public:
    /**
     * @brief Default constructor.
     * 
     * Initializes the cell as dead.
     */
    Cell() = default;

    /**
     * @brief Explicit constructor.
     * 
     * @param alive Initial state of the cell (true for alive).
     */
    explicit Cell(bool alive) : m_alive(alive) {}

    /**
     * @brief Checks if the cell is alive.
     * 
     * @return true if alive, false otherwise.
     */
    [[nodiscard]] bool isAlive() const;

    /**
     * @brief Sets the state of the cell.
     * 
     * @param state New state (true for alive).
     */
    void setAlive(bool state);

    /**
     * @brief Equality operator.
     * 
     * @param other The cell to compare with.
     * @return true if both cells have the same state.
     */
    bool operator==(const Cell& other) const;

    /**
     * @brief Toggles the cell state.
     * 
     * Alive becomes dead, dead becomes alive.
     */
    void toggle();

private:
    bool m_alive = false; ///< The state of the cell.
};

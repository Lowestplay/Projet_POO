#include "../include/Cell.hpp"

/**
 * @brief Returns the cell state.
 */
bool Cell::isAlive() const {
    return m_alive;
}

/**
 * @brief Sets the cell state.
 */
void Cell::setAlive(bool state) {
    m_alive = state;
}

/**
 * @brief Equality operator implementation.
 */
bool Cell::operator==(const Cell& other) const {
    return m_alive == other.m_alive;
}

/**
 * @brief Toggles the cell state.
 */
void Cell::toggle() {
    m_alive = !m_alive;
}
#include "../include/Cell.hpp"

bool Cell::isAlive() const {
    return m_alive;
}

void Cell::setAlive(bool state) {
    m_alive = state;
}

// Implémentation de la comparaison
bool Cell::operator==(const Cell& other) const {
    return m_alive == other.m_alive;
}

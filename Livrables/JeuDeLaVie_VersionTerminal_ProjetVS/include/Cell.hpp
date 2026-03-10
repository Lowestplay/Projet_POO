#pragma once

// Représente une cellule unique.
class Cell {
public:
    Cell() = default;

    // Constructeur explicite
    explicit Cell(bool alive) : m_alive(alive) {}

    // Vérifie si la cellule est vivante.
    [[nodiscard]] bool isAlive() const;

    // Définit l'état de la cellule.
    void setAlive(bool state);

    // Comparaison pour la stabilité 
    bool operator==(const Cell& other) const;

private:
    bool m_alive = false;
};

#pragma once
#include "../include/Grid.hpp"

// Classe utilitaire pour gérer le voisinage.
class Neighborhood {
public:
    // Compte les voisins vivants autour d'une coordonnée.
    // grid La grille à analyser.
    // r Ligne de la cellule.
    // c Colonne de la cellule.
    // toroidal Si vrai, active le mode tore (bords connectés).
    static int countNeighbors(const Grid& grid, int r, int c, bool toroidal);
};

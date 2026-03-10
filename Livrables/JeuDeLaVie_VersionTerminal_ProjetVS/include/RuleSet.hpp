#pragma once
#include "../include/Grid.hpp"

// Interface abstraite pour les règles du jeu.
class RuleSet {
public:
    virtual ~RuleSet() = default;

    // Applique les règles pour générer la grille suivante.
    virtual void applyRules(const Grid& current, Grid& next, bool toroidal) = 0;
};

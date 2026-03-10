#pragma once
#include "../include/RuleSet.hpp"

/**
 * @brief Implementation of Conway's Game of Life rules.
 * 
 * Standard rules:
 * - Underpopulation: Alive cell with < 2 neighbors dies.
 * - Survival: Alive cell with 2 or 3 neighbors lives.
 * - Overpopulation: Alive cell with > 3 neighbors dies.
 * - Reproduction: Dead cell with exactly 3 neighbors becomes alive.
 */
class ConwayRuleSet : public RuleSet {
public:
    /**
     * @brief Applies Conway's rules.
     * 
     * @param current The current grid state.
     * @param next The next grid state (modified in place).
     * @param toroidal Whether to use toroidal boundary conditions.
     */
    void applyRules(const Grid& current, Grid& next, bool toroidal) override;
};

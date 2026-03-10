#pragma once
#include "../include/Grid.hpp"

/**
 * @brief Abstract base class for game rules.
 * 
 * Defines the interface that all rule sets must implement.
 */
class RuleSet {
public:
    /**
     * @brief Virtual destructor.
     */
    virtual ~RuleSet() = default;

    /**
     * @brief Applies the rules to evolve the grid.
     * 
     * @param current The current state of the grid.
     * @param next The grid to store the next state in.
     * @param toroidal Whether the grid wraps around at the edges.
     */
    virtual void applyRules(const Grid& current, Grid& next, bool toroidal) = 0;
};

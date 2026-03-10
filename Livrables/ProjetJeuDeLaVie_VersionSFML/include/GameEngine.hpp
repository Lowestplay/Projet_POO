#pragma once
#include "Grid.hpp"
#include "RuleSet.hpp"
#include <memory>

/**
 * @brief Core engine that manages the simulation logic.
 * 
 * This class holds the current state of the grid, applies the rules of the game
 * to evolve the grid to the next generation, and tracks simulation statistics like iteration count.
 */
class GameEngine {
public:
    /**
     * @brief Constructor for GameEngine.
     * 
     * @param startGrid The initial state of the grid.
     * @param rules A unique pointer to the rule set to be applied (e.g., Conway's rules).
     */
    GameEngine(const Grid& startGrid, std::unique_ptr<RuleSet> rules);

    /**
     * @brief Advances the simulation by one step.
     * 
     * Applies the rules to the current grid to produce the next generation.
     * Updates the iteration count and checks for stability.
     * 
     * @param toroidal If true, the grid is treated as a torus (edges wrap around).
     */
    void step(bool toroidal);

    /**
     * @brief Checks if the simulation has reached a stable state.
     * 
     * @return true if the current grid is identical to the next grid, false otherwise.
     */
    [[nodiscard]] bool isStable() const;

    /**
     * @brief Gets the current grid state (read-only).
     * 
     * @return A const reference to the current Grid object.
     */
    [[nodiscard]] const Grid& getGrid() const;

    /**
     * @brief Gets the current grid state (modifiable).
     * 
     * Useful for direct modifications like clearing the grid or manual cell editing.
     * 
     * @return A reference to the current Grid object.
     */
    [[nodiscard]] Grid& getGridNonConst();

    /**
     * @brief Gets the current iteration number.
     * 
     * @return The number of steps simulated so far.
     */
    [[nodiscard]] int getIteration() const;

    /**
     * @brief Toggles the state of a specific cell.
     * 
     * If the cell is alive, it becomes dead, and vice versa.
     * 
     * @param r Row index of the cell.
     * @param c Column index of the cell.
     */
    void toggleCell(int r, int c);

private:
    Grid m_current;                 ///< The current state of the grid.
    Grid m_next;                    ///< Buffer for the next state of the grid.
    std::unique_ptr<RuleSet> m_rules; ///< The ruleset used for simulation.
    int m_iteration = 0;            ///< Counter for the number of generations.
    bool m_isStable = false;        ///< Flag indicating if the simulation is stable.
};

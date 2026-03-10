#include "../include/GameEngine.hpp"

/**
 * @brief Constructor implementation.
 * 
 * Initializes the current grid and the rule set.
 */
GameEngine::GameEngine(const Grid& startGrid, std::unique_ptr<RuleSet> rules)
    : m_current(startGrid), m_rules(std::move(rules)) {
}

/**
 * @brief Advances the simulation by one step.
 * 
 * 1. Applies rules to generate the next state in m_next.
 * 2. Compares m_next with m_current to detect stability.
 * 3. Updates m_current to m_next.
 * 4. Increments the iteration counter.
 */
void GameEngine::step(bool toroidal) {
    m_rules->applyRules(m_current, m_next, toroidal);
    if (m_next == m_current) m_isStable = true;
    else m_isStable = false;

    m_current = m_next;
    m_iteration++;
}

/**
 * @brief Checks stability.
 */
bool GameEngine::isStable() const { return m_isStable; }

/**
 * @brief Returns read-only grid.
 */
const Grid& GameEngine::getGrid() const { return m_current; }

/**
 * @brief Returns modifiable grid.
 */
Grid& GameEngine::getGridNonConst() { return m_current; }

/**
 * @brief Returns iteration count.
 */
int GameEngine::getIteration() const { return m_iteration; }

/**
 * @brief Toggles a cell's state.
 * 
 * Checks bounds before toggling.
 */
void GameEngine::toggleCell(int r, int c) {
    if (r >= 0 && r < m_current.getRows() && c >= 0 && c < m_current.getCols()) {
        bool current = m_current.getCell(r, c).isAlive();
        m_current.setCell(r, c, !current);
    }
}
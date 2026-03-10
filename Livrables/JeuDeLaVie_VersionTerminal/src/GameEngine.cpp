#include "../include/GameEngine.hpp"

GameEngine::GameEngine(const Grid& startGrid, std::unique_ptr<RuleSet> rules)
    : m_current(startGrid), m_rules(std::move(rules)) {
}

void GameEngine::step(bool toroidal) {
    // 1. Calculer la prochaine étape dans m_next
    m_rules->applyRules(m_current, m_next, toroidal);

    // 2. Vérifier la stabilité (si next est identique à current)
    if (m_next == m_current) {
        m_isStable = true;
    }
    else {
        m_isStable = false;
    }

    // 3. Appliquer le changement
    m_current = m_next;
    m_iteration++;
}

bool GameEngine::isStable() const {
    return m_isStable;
}

const Grid& GameEngine::getGrid() const {
    return m_current;
}

int GameEngine::getIteration() const {
    return m_iteration;
}
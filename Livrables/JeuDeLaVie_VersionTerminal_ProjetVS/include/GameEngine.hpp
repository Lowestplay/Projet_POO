#pragma once
#include "Grid.hpp"
#include "RuleSet.hpp"
#include <memory>

class GameEngine {
public:
    GameEngine(const Grid& startGrid, std::unique_ptr<RuleSet> rules);

    void step(bool toroidal);
    [[nodiscard]] bool isStable() const;
    [[nodiscard]] const Grid& getGrid() const;
    [[nodiscard]] int getIteration() const;

private:
    Grid m_current;
    Grid m_next;
    std::unique_ptr<RuleSet> m_rules;
    int m_iteration = 0;
    bool m_isStable = false; 
};

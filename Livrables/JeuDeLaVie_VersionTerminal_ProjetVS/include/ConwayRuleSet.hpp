#pragma once
#include "../include/RuleSet.hpp"

// Implémentation des règles classiques de Conway.
class ConwayRuleSet : public RuleSet {
public:
    void applyRules(const Grid& current, Grid& next, bool toroidal) override;
};

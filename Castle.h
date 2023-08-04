#pragma once

#include "Structure.h"

class Castle : public Structure {
    // container of subordinate villages?

public:
    Castle(const std::string &name, Point position, int hay);
    void update() override;
    void giveCrates(int crates);
};

#pragma once

#include "Agent.h"
class Knight : public Agent {

    std::string home_castle;

public:
    Knight(std::string &name, Point &position);
    void
    update() override; // check if there is a thug attacking a peasant nearby
};

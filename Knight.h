#pragma once

// for getInstance of the Knight
#include <memory>
//
#include "Agent.h"
#include "Castle.h"
#include <vector>

class Knight : public Agent {

    Knight(const std::string &basicString, Point point);
    std::vector<std::shared_ptr<Structure>> visited;
    shared_ptr<Castle> home_castle;

    enum knight_state { OnPatrol, OnCourse, ToPosition } knight_state;

public:
    static std::shared_ptr<Knight> getInstance(const string &name, Point &p);
    // check if there is a thug attacking a peasant nearby
    void update() override;
    void setDestination(const std::string &structure);
    void broadcast_current_state() const noexcept override;
};

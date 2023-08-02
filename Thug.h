#pragma once

#include <memory>
#include "Agent.h"
#include "Peasant.h"
#include "Geometry.h"
#include <utility>
#include <list>

class Thug : public Agent {

private:

    Thug(const std::string &name_, Point &position,int speed);
    shared_ptr<Peasant> _peasant;
    shared_ptr<list<shared_ptr<Agent>>> agents;

public:
    void update() override;

    void attack(shared_ptr<Peasant> peasant); // check if there is a peasant nearby to attack

    static std::shared_ptr<Thug> getThug(string &basicString,Point &point, int speed);

    void broadcast_current_state() const noexcept override;

    bool check_for_knight();
};

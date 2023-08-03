#pragma once

#include <memory>
#include "Agent.h"
#include "Peasant.h"
#include "Geometry.h"
#include <utility>
#include <vector>

class Thug : public Agent {

private:

    shared_ptr<Peasant> _peasant;
    shared_ptr<vector<shared_ptr<Agent>>> agents;

public:
    Thug(const std::string &name_, Point &position);

    void update() override;

    void attack(shared_ptr<Peasant> peasant,shared_ptr<vector<shared_ptr<Agent>>> agents_); // check if there is a peasant nearby to attack


    void broadcast_current_state() const noexcept override;

    bool check_for_knight();
    void stop() override;

    void setDestinationCoordinates(Point destination) override;
    void setCourse(double theta) override;


};

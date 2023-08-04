#pragma once


#include "Agent.h"
#include "Knight.h"
#include "Peasant.h"
#include <memory>
#include <vector>
#include <algorithm>
#include <iostream>

class Thug : public Agent {

private:
    std::shared_ptr<Peasant> _peasant;
    std::shared_ptr<std::vector<std::shared_ptr<Agent>>> agents;

public:
    Thug(const std::string &name_, Point &position);

    void update() override;

    void attack(std::shared_ptr<Peasant> peasant,
                std::shared_ptr<std::vector<std::shared_ptr<Agent>>>
                    agents_); // check if there is a peasant nearby to attack

    void broadcast_current_state() const noexcept override;

    bool check_for_knight();
    void stop() override;

    void setDestinationCoordinates(Point destination) override;
    void setCourse(double theta) override;
};

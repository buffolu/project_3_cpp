#pragma once

#include <memory>
#include "Agent.h"
#include "Peasant.h"
#include "Geometry.h"
#include <utility>

class Thug : public Agent {

private:

    Thug(std::string &name_, Point &position,int speed);
    shared_ptr<Peasant> _peasant;

public:
    void update() override;

    void attack(shared_ptr<Peasant> peasant); // check if there is a peasant nearby to attack

    static std::shared_ptr<Thug> getThug(string &basicString,Point &point, int speed);
};

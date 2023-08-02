#pragma once

#include "Agent.h"
// for getInstance of the Knight
#include <memory>

class Knight : public Agent {

    std::string home_castle;

public:
    Knight(const std::string &basicString, Point point);
    static std::shared_ptr<Knight> getInstance(const string& name, Point& p);
    void update() override; // check if there is a thug attacking a peasant nearby
    void setDestination(string stracture);
};

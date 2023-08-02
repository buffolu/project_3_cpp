#pragma once

// for getInstance of the Knight
#include <memory>
//
#include "Agent.h"
#include "Castle.h"
#include "list"

class Knight : public Agent {

    Knight(const std::string &basicString, Point point);
    shared_ptr<list<shared_ptr<Structure>>> myStructures;
    list<string> visited;
    shared_ptr<Castle> home_castle;

    Point destination;

    bool OnCourse;
    bool OnPatrol;
    bool ToPosition;

public:
    static std::shared_ptr<Knight> getInstance(const string &name, Point &p);
    void
    update() override; // check if there is a thug attacking a peasant nearby
    void setDestination(const std::string &structure);
};

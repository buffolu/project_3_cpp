#pragma once

// for getInstance of the Knight
#include <memory>
#include <vector>
#include <algorithm>
//
#include "Agent.h"
#include "Castle.h"
#include "list"


class Knight : public Agent {

    Knight(const std::string &basicString, Point point);
    shared_ptr<list<shared_ptr<Structure>>> myStructures;
    std::vector<string> visited;
    shared_ptr<Structure> home_castle;
    shared_ptr<Structure> next_castle;

    bool going_home; // knight is going back to his original structure

public:
    static std::shared_ptr<Knight> getInstance(const string &name, Point &p);
    void
    update() override; // check if there is a thug attacking a peasant nearby
    void setOnPatrol(const shared_ptr<Structure>& structure, const shared_ptr<list<shared_ptr<Structure>>> & structures);
    void broadcast_current_state() const noexcept override;
    void stop() override;
    shared_ptr<Structure> check_for_closest();


     void setDestinationCoordinates(Point destination) override;

     void setCourse(double theta) override;



};

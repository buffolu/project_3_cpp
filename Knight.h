#pragma once

// for getInstance of the Knight
#include <algorithm>
#include <memory>
#include "Geometry.h"
//
#include "Agent.h"
#include "Castle.h"
#include <vector>
#include "Structure.h"
#include <memory>
#include <cfloat>
#include <iostream>

class Knight : public Agent {

    std::shared_ptr<std::vector<std::shared_ptr<Structure>>> myStructures;
    std::vector<std::string> visited;
    std::shared_ptr<Structure> home_castle;
    std::shared_ptr<Structure> destination_structure;

    bool going_home; // knight is going back to his original structure

public:
    Knight(const std::string &basicString, Point point);
    // check if there is a thug attacking a peasant nearby
    void update() override;
    void setOnPatrol(std::shared_ptr<Structure> structure,
                     std::shared_ptr<std::vector<std::shared_ptr<Structure>>> structures);
    void broadcast_current_state() const noexcept override;
    void stop() override;
    std::shared_ptr<Structure> check_for_closest();

    void setDestinationCoordinates(Point destination) override;

    void setCourse(double theta) override;
};

//
// Created by igor on 24/06/2023.
//

#include "Knight.h"

Knight::Knight(const std::string &name, Point position)
    : Agent(name, position, 10, 1) {}

void Knight::update() {
    Agent::update();
    if (getState() == ON_DUTY) {
        if (getLocation() ==
            destination_structure
                ->getLocation()) { // continue the patrol to a new structure
            if (getLocation() == home_castle->getLocation() &&
                going_home) // knight reached the end
            {
                stop();
                return;
            }
            destination_structure =
                check_for_closest(); // with visited and mystructres}
            if (destination_structure == home_castle) {
                going_home = true;
            } // knight is ending his patrol

            setAngle(Point ::getAngle(
                getLocation(),
                destination_structure
                    ->getLocation())); // set a new direction(angle)
        }
        setLocation(
            Point::advance(getLocation(), destination_structure->getLocation(),
                           getSpeed())); // advance towards new direction
    }
}

void Knight::setOnPatrol(
    std::shared_ptr<Structure> structure_,
    std::shared_ptr<std::vector<std::shared_ptr<Structure>>> structures) {
    setState(ON_DUTY);
    home_castle = structure_;
    destination_structure = home_castle;
    visited.push_back(structure_->getName());
    setAngle(Point::getAngle(
        getLocation(), structure_->getLocation())); // angle of riding direction
    myStructures = structures;
}

void Knight::broadcast_current_state() const noexcept {
    Agent::broadcast_current_state();
    if (getState() == ON_DUTY) {
        std::cout << " patrolling around " << destination_structure->getName();
    }
    std::cout << std::endl;
}
std::shared_ptr<Structure> Knight::check_for_closest() {
    if (visited.size() == myStructures->size())
        return nullptr;

    double min = DBL_MAX;
    double tmp;
    std::shared_ptr<Structure> structure;
    for (const auto &obj : *myStructures) {
        auto it = find(visited.begin(), visited.end(), obj->getName());
        if (it == visited.end()) // this line means that this structure is not
                                 // visited yet
        {
            tmp = Point::distance(getLocation(), obj->getLocation());
            if (tmp < min) {
                min = tmp;
                structure = obj;
            } else if (tmp == min &&
                       obj->getName().front() <
                           structure->getName()
                               .front()) // choose by alphabetic order
            {
                min = tmp;
                structure = obj;
            }
        }
    }
    visited.emplace_back(structure->getName());
    return structure;
}

void Knight::stop() {
    Agent::stop();
    myStructures.reset();
    going_home = false;
    visited.clear();
}

void Knight::setDestinationCoordinates(Point destination) {
    stop();
    Agent::setDestinationCoordinates(destination);
}

void Knight::setCourse(double theta) {
    stop();
    Agent::setCourse(theta);
}

//
// Created by igor on 24/06/2023.
//
#include "Peasant.h"

Peasant::Peasant(std::string &name, Point &position) : Agent(name, position,10,5) {

}

shared_ptr<Peasant> Peasant::getInstance(string &name, Point &position) {
    return shared_ptr<Peasant>(new Peasant(name,position));
}

void Peasant::start_working(shared_ptr<Farm> farm, shared_ptr<Castle> castle) {
    _farm = farm;
    _castle = castle;
    this->move_to_place(farm->getLocation());
    is_working = true;
}

void Peasant::update() {
    Agent::update();
}


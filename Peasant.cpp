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
    m_farm = farm;
    m_castle = castle;
    position(farm->getLocation());
    is_working = true;
}

void Peasant::update() {
    // Agent::update();

}

int Peasant::getCarriedCrates() const { return carried_crates; }

bool Peasant::isWorking() const { return is_working; }

void Peasant::setCarriedCrates(int carriedCrates) {
    carried_crates = carriedCrates;
}

//
// Created by igor on 14/06/2023.
//

#include "Agent.h"

void Agent::update() {
    if (state == MOVING_TO_POSITION) {
        // move agent
    }
}

Agent::Agent(const string &name_, Point location_, int speed_, int health_)
    : Sim_object(name_, location_), speed(speed_), state(STOPPED),
      health(health_) {}

void Agent::move_to_place(Point &destination_) { state = MOVING_TO_POSITION; }

void Agent::move_to_direction(double theta) {}

void Agent::stop() { state = STOPPED; }

int Agent::getType() { return type; }

std::string Agent::getName() { return std::string(); }

int Agent::getState() const {
    return state;
}

const Point &Agent::getDestination() const {
    return destination;
}

double Agent::getSpeed() const {
    return speed;
}

int Agent::getHealth() const {
    return health;
}

void Agent::setDestination(const Point &destination) {
    Agent::destination = destination;
}

void Agent::setSpeed(double speed) {
    Agent::speed = speed;
}

void Agent::setState(int state) {
    Agent::state = state;
}

void Agent::setHealth(int health) {
    Agent::health = health;
    if (health == 0)
        state = DEAD;
}

}

void Agent::setType(int type) {
    Agent::type = type;
}

//
// Created by igor on 14/06/2023.
//

#include "Agent.h"

Agent::Agent(const std::string &name_, Point location_, int speed_, int health_)
    : Sim_object(name_, location_), speed(speed_), health(health_),
      state(STOPPED) {}

void Agent::update() {
    if (state == MOVING_TO_POSITION || state == MOVING_ON_COURSE) {
        setLocation(
            Point::advance(getLocation(), destination_coordinates, getSpeed()));
        if (state == MOVING_TO_POSITION &&
            getLocation() ==
                destination_coordinates) // the agent reached the destination
        {
            stop();
        }
    }
}

void Agent::stop() {
    if (state != DEAD) {
        state = STOPPED;
        destination_coordinates = getLocation();
    }
    // course unchanged
}

void Agent::setCourse(double theta) {
    state = MOVING_ON_COURSE;
    angle = theta;
    // destination_coordinates unchanged
}

double Agent::getCourse() const { return angle; }

void Agent::setDestinationCoordinates(Point destination_) {
    state = MOVING_TO_POSITION;
    // angle unchanged
    destination_coordinates = destination_;
    // course unchanged
}

Point Agent::getDestinationCoordinates() const {
    return destination_coordinates;
}

int Agent::getState() const { return state; }

void Agent::setSpeed(double speed_) { Agent::speed = speed_; }

double Agent::getSpeed() const { return speed; }

void Agent::setHealth(int health1) {
    if (health1 > 20) {
        std::cout << "value too high, result in default value of 5 health";
        health = 5;
    } else {
        health = health1;
        if (health == 0)
            state = DEAD;
    }
}

int Agent::getHealth() const { return health; }

void Agent::broadcast_current_state() const noexcept {
    Sim_object::broadcast_current_state();
    if (state == MOVING_TO_POSITION) {
        std::cout << " heading to: (" << getDestinationCoordinates().x << ", "
                  << getDestinationCoordinates().y << "), at speed: " << speed;
    } else if (getState() == MOVING_ON_COURSE) {
        std::cout << " heading on course " << std::to_string(getAngle())
                  << " deg, speed " << getSpeed() << " km/h";
    } else if (state == DEAD) {
        std::cout << " dead";
    } else if (state == STOPPED) {
        std::cout << " stopped";
    }
    std::cout << " health: " << getHealth();
}

void Agent::setState(enum Agent::state _state) { Agent::state = _state; }

double Agent::getAngle() const { return angle; }

void Agent::setAngle(double angle_) { Agent::angle = angle_; }

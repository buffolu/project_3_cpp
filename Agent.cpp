//
// Created by igor on 14/06/2023.
//

#include "Agent.h"




void Agent::update() {
    if(state == MOVING_TO_POSITION){
        //move agent
    }


}

Agent::Agent(string &name_, Point& location_,int speed_,int health_): Sim_object (name_,location_),
speed(speed_),state(STOPPED),health(health_) {

}

void Agent::move_to_place(Point &destination_) {

    state =MOVING_TO_POSITION;

}

void Agent::move_to_direction(double theta) {

}

void Agent::stop() {
    state = STOPPED;
}

std::string Agent::getType() {
    return  type;
}

std::string Agent::getName() {
    return std::string();
}

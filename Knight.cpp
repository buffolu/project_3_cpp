//
// Created by igor on 24/06/2023.
//
#include "Knight.h"

Knight::Knight(std::string &name, Point &position)
    : Agent(name, position, 10, -1) {
    State = STOPPED;
}

shared_ptr<Knight> Knight::getInstance(string &name, Point &p) {
    if(name.length()<16 && isValid(p)){
        return shared_ptr<Knight>(new Knight(name,p));
    }
}



/**
 * TODO: new functions to implement
 *
 *
 */
void Knight::update() {
    if(getState() != STOPPED && getState() != DEAD)
    {
        if(OnPatrol)
            if(getLocation() == home_castle.getLocation()){ // contuine the patrol to a new structure
                shared_ptr<Structure> structure = check_for_closest();// with visited and mystructres}
                angle = getAngle(getLocation(),structure); // implemnt in geomerty
            }
        }
        position = advance(getLocation(),speed,angle); //implement in geometry
    }

void Knight::setDestination(string& stracture) {
    OnPatrol = true;
    OnCourse = false;
    ToPosition = false;
    home_castle = stracture;

}





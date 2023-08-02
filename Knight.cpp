//
// Created by igor on 24/06/2023.
//
#include "Knight.h"

Knight::Knight(const std::string &name, Point position)
    : Agent(name, position, 10, -1) {
    setState(STOPPED);
}

std::shared_ptr<Knight> Knight::getInstance(const string &name, Point &p) {
    // what is isValid
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
        if(OnPatrol && getLocation() == home_castle->getLocation()){ // contuine the patrol to a new structure
                shared_ptr<Structure> structure = check_for_closest();// with visited and mystructres}
                angle = getAngle(getLocation(),structure); // implemnt in geomerty
        }
        position = advance(getLocation(),speed,angle); //implement in geometry
    }
}

void Knight::setDestination(const std::string& stracture) {
    OnPatrol = true;
    OnCourse = false;
    ToPosition = false;
    // home_castle = stracture;
}

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
    if(name.length()<16 ){
        return shared_ptr<Knight>(new Knight(name,p));
    }
}



void Knight::update() {
    Agent::update();
    if(getState() == ON_DUTY)
    {
        if(getLocation() == next_castle->getLocation()){ // continue the patrol to a new structure
                if(getLocation() == home_castle->getLocation() && going_home) //knight reached the end
                {
                    stop();
                    return;
                }
                next_castle = check_for_closest();// with visited and mystructres}
                if(next_castle == home_castle) {going_home = true;} //knight is ending his patrol


            setAngle(  Point ::getAngle(getLocation(), next_castle->getLocation())  ); //set a new direction(angle)
        }
        setLocation(Point::advance(getLocation(),getSpeed(), getAngle())); //advance towards new direction
    }




}

void Knight::setOnPatrol(const shared_ptr<Structure>& structure_,const shared_ptr<list<shared_ptr<Structure>>>& structures) {
    setState(ON_DUTY);
    home_castle = structure_;
    next_castle = home_castle;
    setAngle(Point::getAngle(getLocation(),structure_->getLocation())); // angle of riding direction
    myStructures = structures;
}

void Knight::broadcast_current_state() const noexcept {
    Agent::broadcast_current_state();
    if (getState() == ON_DUTY) {
        std::cout << " patrolling around " <<
                  next_castle->getName();

    }
}
shared_ptr<Structure> Knight::check_for_closest() {
        if (visited.size() == myStructures->size()) return nullptr;


        double min = 1000000000000;  //infinity
        double tmp;
        shared_ptr<Structure> structure;
        for (const auto &obj: *myStructures) {
            auto it = find(visited.begin(), visited.end(), obj->getName());
            if (it == visited.end())   //this line means that this structure is not visited yet
            {
                tmp = Point::distance(getLocation(), obj->getLocation());
                if (tmp < min) {
                    min = tmp;
                    structure = obj;
                } else if (tmp == min)   //choose by alphabetic order
                {
                    if (obj->getName().front() < structure->getName().front()) {
                        min = tmp;
                        structure = obj;
                    }
                }
            }
        }
        visited.emplace_back(structure->getName());
        return structure;
    }


void Knight::stop() {
    Agent::stop();
    home_castle.reset();
    next_castle.reset();
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



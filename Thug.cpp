//
// Created by igor on 24/06/2023.
//


#include "Thug.h"




Thug::Thug(const std::string &name_, Point &position): Agent(name_,position,0,5){

}

// TODO: implement this completely again
// this needs to take a peasant and attack it if it is close enough, and no knights are nearby
void Thug::attack(std::shared_ptr<Peasant> peasant,std::shared_ptr<std::vector<std::shared_ptr<Agent>>> agents_) {
    if(getState() == DEAD || peasant->getState() == DEAD) {} //thug or peasant are dead
        /*
         * TODO: EITHER DO NOTHING OR THROW EXCPETION
         *
         */
    else{

        setState(ON_DUTY);
        agents = std::move(agents_);
        _peasant = std::move(peasant);
    }

}

void Thug::update() {
    Agent::update();
    if(getState() == ON_DUTY){ //there is a peasant that needs to be attacked
            if (Point::distance(_peasant->getLocation(), getLocation()) <= 1 && //peasant is close enough
                !check_for_knight()) //no knights around
            {
                //initiate attack !
                if (getHealth() >= _peasant->getHealth()) //attack successful
                {
                    _peasant->setState(STOPPED);
                    _peasant->setCarriedCrates(0);
                    setHealth(getHealth() + 1);
                }
                else {
                    setHealth(getHealth() - 1);     //attack unsuccessful
                }
                //attack completed !
                _peasant->setHealth(_peasant->getHealth() - 1);
                _peasant.reset();
                stop();
                return;
            }

            //one of the conditions is not satisfied
            else{
                double angle1 = Point::getAngle(getLocation(), _peasant->getLocation());
                setLocation(Point::advance(getLocation(), getSpeed(), angle1));
            }
        }
}



void Thug::broadcast_current_state() const noexcept {
    Agent::broadcast_current_state();
}

bool Thug::check_for_knight() {
   return std::any_of(agents->begin(),agents->end(),[this](std::shared_ptr<Agent> agent)
   {
       return (std::dynamic_pointer_cast<Knight>(agent) &&
                Point::distance(getLocation(),agent->getLocation()) <= 2.5)
   ;})
   ;
}

void Thug::stop() {
    Agent::stop();
    agents.reset();
    _peasant.reset();
}

void Thug::setCourse(double theta) {
    stop();
    Agent::setCourse(theta);
}

void Thug::setDestinationCoordinates(Point destination) {
    stop();
    Agent::setDestinationCoordinates(destination);
}


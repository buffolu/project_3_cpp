//
// Created by igor on 24/06/2023.
//

#include "Thug.h"



std::shared_ptr<Thug> Thug::getThug(string &name, Point &point, int speed) {
    if(speed > 30 || name.length() > 16 || out_of_scope(point))
    {
        throw exception(); // throw suitable exception
    }

    return shared_ptr<Thug>(new Thug(name,point,speed));
}

Thug::Thug(const std::string &name_, Point &position, int speed): Agent(name,position,speed,5){

}

void Thug::attack(shared_ptr<Peasant> peasant) {
    if(getState() == DEAD || peasant->getState() == DEAD) {} //thug or peasant are dead
        /*
         * TODO: EITHER DO NOTHING OR THROW EXCPETION
         *
         */
    else{


        _peasant = std::move(peasant);
        _isAttacking = true;
    }

}

void Thug::update() {
    if(state == MOVING_TO_POSITION){
        if(workingState == OnDuty)  //there is a peasant that needs to be attacked
        {
            if (Point::distance(_peasant->getLocation(), getLocation()) <= 1 &&
                !check_for_knight()) //peasant is close enough
            {
                if (getHealth() >= _peasant->getHealth()) //attack succsesfull
                {
                    _peasant->setState(STOPPED);
                    _peasant->setCarriedCrates(0);
                    setHealth(getHealth() + 1);
                } else {
                    setHealth(getHealth() - 1);
                }
                _peasant->setHealth(_peasant->getHealth() - 1);
                _peasant.reset(); // attack completed.
                setState(STOPPED);
                return;
            }
            else{
                double angle = Point::getAngle(getLocation(), _peasant->getLocation());
                setLocation(Point::advance(getLocation(), getSpeed(), angle));
            }

        }
        else {  // Thug either  on course or moving towards some position.
            setLocation(Point::advance(getLocation(), getSpeed(), angle));
            if(workingState == ToPosition && getLocation() == getDestination())
            {
                state = STOPPED;
            }
        }




    }


}

// void Thug::attack(shared_pt) {
//
// }


void Thug::broadcast_current_state() const noexcept {
    Agent::broadcast_current_state();
}

bool Thug::check_for_knight() {
    return false;
}

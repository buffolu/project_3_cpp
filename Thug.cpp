//
// Created by igor on 24/06/2023.
//

#include <algorithm>
#include <utility>
#include "Thug.h"
#include "Knight.h"


std::shared_ptr<Thug> Thug::getThug(string &name, Point &point, int speed) {
    if(speed > 30 || name.length() > 16 )
    {
        throw exception(); // throw suitable exception
    }

    return shared_ptr<Thug>(new Thug(name,point,speed));
}

Thug::Thug(const std::string &name_, Point &position, int speed): Agent(name_,position,speed,5){

}

void Thug::attack(shared_ptr<Peasant> peasant,shared_ptr<list<shared_ptr<Agent>>> agents_) {
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
                if (getHealth() >= _peasant->getHealth()) //attack successful
                {
                    _peasant->setState(STOPPED);
                    _peasant->setCarriedCrates(0);
                    setHealth(getHealth() + 1);
                } else {
                    setHealth(getHealth() - 1);
                }
                _peasant->setHealth(_peasant->getHealth() - 1);
                _peasant.reset(); // attack completed.
                stop();
                return;
            }
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
   return std::any_of(agents->begin(),agents->end(),[this](shared_ptr<Agent>& agent)
   {
       return (dynamic_pointer_cast<Knight>(agent) &&
                Point::distance(getLocation(),agent->getLocation()) <= 2.5)
   ;})
   ;
}

void Thug::stop() {
    Agent::stop();
    agents.reset();
    _peasant.reset();
}

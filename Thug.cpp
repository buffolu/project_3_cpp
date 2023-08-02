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

Thug::Thug(string &name_, Point &position, int speed): Agent(name,position,speed,5){

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
    if(_peasant)  //there is a peasant that needs to be attacked
    {
        if(distance(_peasant->getLocation(),getLocation()) <= 1  && !check_for_knight())
        {
                if(getHealth() >= _peasant->getHealth()) //attack succsesfull
                {
                    _peasant->setState(STOPPED);
                    _peasant->setCrates(0);
                    setHealth(getHealth()+1);
                    setState(STOPPED);
                }
                else{
                    setHealth(getHealth()-1);
                }
                _peasant->setHealth(_peasant->getHealth()-1);
                _peasant = nullptr; // attack completed.
        }

    }
}

// void Thug::attack(shared_pt) {
//
// }

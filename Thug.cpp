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
    if(getState() == DEAD) {}
        /*
         * TODO: EITHER DO NOTHING OR THROW EXCPETION
         *
         */
    else{
        _peasant = std::move(peasant);
    }

}

void Thug::update() {
    if(_peasant)  //there is a peasant that needs to be attacked
    {
        if(distance(_peasant->getLocation(),getLocation()) <= 1 )
        {
            if (Model::)

        }



    }
}

// void Thug::attack(shared_pt) {
//
// }

//
// Created by igor on 24/06/2023.
//


#include "Thug.h"




Thug::Thug(const std::string &name_, Point &position): Agent(name_,position,0,5){

}


void Thug::attack(std::shared_ptr<Peasant>& _peasant,std::shared_ptr<std::vector<std::shared_ptr<Agent>>> agents_) {
    if(getState() == DEAD || _peasant->getState() == DEAD) {} //thug or peasant are dead
        /*
         * TODO: EITHER DO NOTHING OR THROW EXCPETION
         *
         */
    else{

        //2 necessary conditions for attack
        if (Point::distance(_peasant->getLocation(), getLocation()) <= 1 && //peasant is close enough
            !check_for_knight(agents_)) //no knights around
        {

            //initiate attack !
            if (getHealth() > _peasant->getHealth()) //attack successful
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
            stop();
            return;
        }

            //one of the conditions is not satisfied -  //attack unsuccessful.
        else{
            setHealth(getHealth() - 1);
            stop();
        }

}}

void Thug::update() {
    Agent::update();

}



void Thug::broadcast_current_state() const noexcept {
    Agent::broadcast_current_state();
}

bool Thug::check_for_knight(std::shared_ptr<std::vector<std::shared_ptr<Agent>>> agents) {
   return std::any_of(agents->begin(),agents->end(),[this](std::shared_ptr<Agent> agent)
   {
       return (std::dynamic_pointer_cast<Knight>(agent) &&
                Point::distance(getLocation(),agent->getLocation()) <= 2.5)
   ;})
   ;
}




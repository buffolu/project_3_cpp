//
// Created by igor on 24/06/2023.
//
#include "Peasant.h"

Peasant::Peasant(std::string &name, Point &position) : Agent(name, position,10,5),carried_crates(0),is_working(false) {

}

shared_ptr<Peasant> Peasant::getInstance(string &name, Point &position) {
    return shared_ptr<Peasant>(new Peasant(name,position));
}

void Peasant::start_working(const shared_ptr<Farm>& farm,const shared_ptr<Castle>& castle) {
    m_farm = farm;
    m_castle = castle;
    setState(ON_DUTY);
    setAngle(Point::getAngle(getLocation(),m_farm->getLocation()));
    loading = true;
}

void Peasant::update() {
     if(getState() == ON_DUTY)
     {
        if(getLocation() == m_farm->getLocation()) // peasant reached the farm
        {
            if(loading) { // peasant needs to load
                carried_crates = m_farm->takeCrates();
                loading = false;
            }
            else //set new direction for peasant
            {
                setAngle( Point::getAngle(getLocation(),m_castle->getLocation()));
            }
        }
        if(getLocation() == m_castle->getLocation()) //peasant reached the castle, unload and stop
        {

                m_castle->giveCrates(carried_crates);
                setHealth(getHealth()+1);
                stop();

        }
        else //peasant is still on his way, advance
        {

            setLocation(Point::advance(getLocation(),getSpeed(),getAngle()));

        }

     }

}

int Peasant::getCarriedCrates() const { return carried_crates; }


void Peasant::setCarriedCrates(int carriedCrates) {
    carried_crates = carriedCrates;
}

void Peasant::stop() {
    setState(STOPPED);
    m_castle.reset();
    m_farm.reset();
    carried_crates = 0;

}

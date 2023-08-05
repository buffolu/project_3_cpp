//
// Created by igor on 24/06/2023.
//
#include "Peasant.h"

Peasant::Peasant(const std::string &name, Point &position)
    : Agent(name, position, 5, 10), carried_crates(0), loading(true) {}

// add another farm and castle to peasant , make him to begin work if he doesn't
// do anything(Stopped)
void Peasant::start_working(const std::shared_ptr<Farm> &farm,
                            const std::shared_ptr<Castle> &castle) {
    if (getState() != DEAD) {
        farms.push(farm);
        castles.push(castle);
        if (castles.size() == 1) {
            nextPair();
        }
    } else {
        std::cout << "this peasant is dead unfortunately\n";
    } // peasant is dead, nothing we can do...
}

// make him work on the next pair
void Peasant::nextPair() {
    m_farm = farms.front(), m_castle = castles.front();
    loading = true;
    setState(ON_DUTY);
    setAngle(Point::getAngle(getLocation(), m_farm->getLocation()));
}
void Peasant::update() {
    Agent::update();
    if (getState() == ON_DUTY) {
        if (getLocation() == m_farm->getLocation() &&
            loading) // peasant reached the farm
        {
            carried_crates = m_farm->takeCrates();
            loading = false;
            setAngle(Point::getAngle(getLocation(), m_castle->getLocation()));
        }
        if (getLocation() == m_castle->getLocation() &&
            !loading) // peasant reached the castle, unload and stop
        {

            m_castle->giveCrates(carried_crates);
            carried_crates = 0;
            setHealth(getHealth() + 1);
            farms.pop();
            castles.pop();
            if (castles.empty()) {
                stop();
            } else {
                nextPair();
            }

        } else // peasant is still on his way, advance
        {
            if (loading) {
                if (Point::distance(getLocation(), m_farm->getLocation()) <
                    getSpeed())
                    setLocation(m_farm->getLocation());
                else {
                    setLocation(Point::advance(getLocation(),
                                               getDestinationCoordinates(),
                                               getAngle()));
                }
            } else {
                if (Point::distance(getLocation(), m_castle->getLocation()) <
                    getSpeed())
                    setLocation(m_castle->getLocation());
                else {
                    setLocation(Point::advance(getLocation(),
                                               getDestinationCoordinates(),
                                               getAngle()));
                }
            }
        }
    }
}

int Peasant::getCarriedCrates() const { return carried_crates; }

void Peasant::setCarriedCrates(int carriedCrates) {
    carried_crates = carriedCrates;
}
void Peasant::broadcast_current_state() const noexcept {
    std::cout << "Peasant: ";
    Agent::broadcast_current_state();
    if (getState() == ON_DUTY) {
        std::cout << " inventory: " << carried_crates;
    }
    std::cout << ", health:" << getHealth();
}

void Peasant::stop() { // beside the change of state, it also makes sense to use
                       // it when killing the farmer
    Agent::stop();
    m_castle.reset();
    m_farm.reset();
    while (!farms.empty())
        farms.pop();
    while (!castles.empty())
        castles.pop();

    carried_crates = 0;
}

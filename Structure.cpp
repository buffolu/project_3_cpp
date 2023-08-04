//
// Created by igor on 14/06/2023.
//

#include "Structure.h"

#include <utility>

void Structure::deposit(int amount) {
    if (amount > 0)
        _hay += amount;
}

bool Structure::withdraw(int amount) {
    if (amount > 0 && amount <= _hay) {
        _hay -= amount;
	return true;	// successfully withdrawn
    }
    return false;	// failed to withdraw
}

void Structure::broadcast_current_state() const noexcept {
    Sim_object::broadcast_current_state();
    std::cout << ", hay: " << _hay;
}

Structure::Structure(string name, Point location, int hay, int type): Sim_object(std::move(name),location,type),_hay(hay) {}

void Structure::addToHay(int amount) {
    _hay+=amount;
}

int Structure::getHay() const {
    return _hay;
}

void Structure::setHay(int val) {
    _hay = val;
}



//
// Created by igor on 14/06/2023.
//

#include "Structure.h"
#include <iostream>

void Structure::broadcast_current_state() const noexcept {
    Sim_object::broadcast_current_state();
    std::cout << ", hay: " << _hay;
}

Structure::Structure(const std::string &name, Point location, int hay): Sim_object(std::move(name),location),_hay(hay) {}

void Structure::addToHay(int amount) {
    _hay+=amount;
}

int Structure::getHay() const {
    return _hay;
}

void Structure::setHay(int val) {
    _hay = val;
}

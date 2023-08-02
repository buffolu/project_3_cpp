//
// Created by igor on 14/06/2023.
//

#include "Sim_object.h"

Sim_object::Sim_object(const string &name_, Point location_) {
    name = name_;
    location = location_;
}

std::string Sim_object::getName() const noexcept { return name; }

Point Sim_object::getLocation() const noexcept { return location; }

void Sim_object::broadcast_current_state() const noexcept {
    std::cout << "name: " << name << " at position: (" << location.x << ", "
              << location.y << "),";
}

//
// Created by igor on 14/06/2023.
//

#include "Sim_object.h"

#include <utility>

Sim_object::Sim_object(string name_, Point location_,int type) : name(std::move(name_)), location(location_),type(type) {
}

void Sim_object::setName(const std::string& name_) {
    name = name_;
}

std::string Sim_object::getName() const noexcept { return name; }

void Sim_object::setLocation(Point location_) {
    location = location_;
}

Point Sim_object::getLocation() const noexcept { return location; }

void Sim_object::broadcast_current_state() const noexcept {
    std::cout << "name: " << name << " at position: (" << location.x << ", "
              << location.y << "),";
}
int Sim_object::getType() const {
    return type;
}



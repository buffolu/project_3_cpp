//
// Created by igor on 14/06/2023.
//

#ifndef PROJECT_3_SIM_OBJECT_H
#define PROJECT_3_SIM_OBJECT_H

#include "Geometry.h"
#include <iostream>

class Sim_object {
    std::string name;
    Point location;

protected:
    void broadcast_current_state() const noexcept;

public:
    Sim_object(const std::string &name_, Point location_);
    virtual void update() = 0;

    std::string getName() const noexcept;

    Point getLocation() const noexcept;
};

#endif // PROJECT_3_SIM_OBJECT_H

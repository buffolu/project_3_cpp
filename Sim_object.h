//
// Created by igor on 14/06/2023.
//

#ifndef PROJECT_3_SIM_OBJECT_H
#define PROJECT_3_SIM_OBJECT_H

#include "Geometry.h"
// #include <iostream>

class Sim_object {
    std::string name;
    Point _location;

protected:
    virtual void broadcast_current_state() const noexcept;

public:
    Sim_object(const std::string &name_, Point location_);
    virtual void update() = 0;

    std::string getName() const noexcept;

    // setLocation
    Point getLocation() const noexcept;

    void setLocation(const Point &location);
};

#endif // PROJECT_3_SIM_OBJECT_H

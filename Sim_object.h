//
// Created by igor on 14/06/2023.
//

#ifndef PROJECT_3_SIM_OBJECT_H
#define PROJECT_3_SIM_OBJECT_H

#include "Geometry.h"
#include <string>
#include <iostream>
class Sim_object {
    std::string name;
    Point location;
public:
    Sim_object(const std::string &name_, Point location_);
    virtual void update() = 0;

    void setName(const std::string& name);
    std::string getName() const noexcept;

    void setLocation(Point location);
    Point getLocation() const noexcept;

    int getType() const;

    virtual void broadcast_current_state() const noexcept;

    virtual ~Sim_object() = 0;
};

#endif // PROJECT_3_SIM_OBJECT_H

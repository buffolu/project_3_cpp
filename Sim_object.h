//
// Created by igor on 14/06/2023.
//

#ifndef PROJECT_3_SIM_OBJECT_H
#define PROJECT_3_SIM_OBJECT_H

#include "Geometry.h"
// #include <iostream>

class Sim_object {
    std::string name;
    Point location;
    int type;
public:
    enum type_info {PEASANT,KNIGHT,THUG,FARM,CASTLE};
    Sim_object(std::string name_, Point location_,int type);
    virtual void update() = 0;

    void setName(const std::string& name);
    std::string getName() const noexcept;

    void setLocation(Point location);
    Point getLocation() const noexcept;

    int getType() const;

    virtual void broadcast_current_state() const noexcept;
};

#endif // PROJECT_3_SIM_OBJECT_H

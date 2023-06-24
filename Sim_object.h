//
// Created by igor on 14/06/2023.
//

#ifndef PROJECT_3_SIM_OBJECT_H
#define PROJECT_3_SIM_OBJECT_H


#include <iostream>
#include "Geometry.h"

class Sim_object {
	std::string name;
	Point location;

	protected:
	std::string getName() const noexcept;
	Point getLocation() const noexcept;

    void broadcast_current_state() const noexcept;

public:
    Sim_object(std::string & name_, Point& location_);
    virtual void update()= 0;
};


#endif //PROJECT_3_SIM_OBJECT_H

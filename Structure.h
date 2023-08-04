//
// Created by igor on 14/06/2023.
//

#ifndef PROJECT_3_STRUCUTE_H
#define PROJECT_3_STRUCUTE_H

#include "Sim_object.h"
#include "Geometry.h"
#include <iostream>
class Structure : public Sim_object {
    int _hay;

public:
    Structure(const std::string &name,Point location,int hay);

    void broadcast_current_state() const noexcept override;
    void addToHay(int amount);
    int getHay() const ;
    void setHay(int val);
};

#endif // PROJECT_3_STRUCUTE_H

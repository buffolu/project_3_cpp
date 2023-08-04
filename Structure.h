//
// Created by igor on 14/06/2023.
//

#ifndef PROJECT_3_STRUCUTE_H
#define PROJECT_3_STRUCUTE_H

#include "Sim_object.h"
#include "Geometry.h"
class Structure : public Sim_object {
    int _hay;

public:
    Structure(string name,Point location,int hay,int type);
    void deposit(int amount);
    bool withdraw(int amount);

    void broadcast_current_state() const noexcept override;
    void addToHay(int amount);
    int getHay() const ;
    void setHay(int val);
};

#endif // PROJECT_3_STRUCUTE_H

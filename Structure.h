//
// Created by igor on 14/06/2023.
//

#ifndef PROJECT_3_STRUCUTE_H
#define PROJECT_3_STRUCUTE_H

#include "Sim_object.h"

class Structure : public Sim_object {
    int hay;

public:
    void deposit(int amount);
    bool withdraw(int amount);

    void broadcast_current_state() const noexcept override;
};

#endif // PROJECT_3_STRUCUTE_H

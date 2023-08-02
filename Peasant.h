#pragma once

#include "Agent.h"
#include "Castle.h"
#include "Farm.h"
#include <string>

class Peasant : public Agent {
    std::shared_ptr<Farm> _farm;
    std::shared_ptr<Castle> _castle;
    int carried_crates;
    bool is_working;

public:
    Peasant(std::string &name, Point &position);
    static shared_ptr<Peasant> getInstance(std::string &name, Point &position);
    void start_working(
        std::shared_ptr<Farm> farm,
        std::shared_ptr<Castle> castle); // make him pick up hay from his
                                         // village and go to his castle
    void update() override;

    int getCarriedCrates() const;

    bool isWorking() const;

    void setCarriedCrates(int carriedCrates);
};

#pragma once

#include "Agent.h"
#include "Castle.h"
#include "Farm.h"
#include <string>

class Peasant : public Agent {
    const static int MAX_CRATES = 5;

    std::shared_ptr<Farm> m_farm;
    std::shared_ptr<Castle> m_castle;
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

    void setCarriedCrates(int cc);
    int getCarriedCrates() const;

    void setWorking(bool work);
    bool isWorking() const;
};

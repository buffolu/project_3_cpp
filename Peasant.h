#pragma once

#include "Agent.h"
#include "Castle.h"
#include "Farm.h"
#include "Geometry.h"
#include <memory>
#include <iostream>
#include <vector>
#include <queue>


class Peasant : public Agent {
    const static int MAX_CRATES = 5;

    std::shared_ptr<Farm> m_farm;
    std::shared_ptr<Castle> m_castle;


    std::queue<std::shared_ptr<Farm>> farms;
    std::queue<std::shared_ptr<Castle>> castles;


    int carried_crates;
    bool loading;

public:
    Peasant(const std::string &name, Point &position);
    void start_working(
        const std::shared_ptr<Farm>& farm,
        const std::shared_ptr<Castle>& castle); // make him pick up hay from his
                                         // village and go to his castle
    void update() override;
    void broadcast_current_state() const noexcept override;
    void setCarriedCrates(int cc);
    int getCarriedCrates() const;
    void stop() override;


};

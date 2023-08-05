#pragma once
/*
 * Peasant class
 * interacts directly with farm and castle , unload and load the hay.
 * only has one work function, does not support course or position
 * can be killed by : thug.
 */
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

    //current farm and castle the peasant is working on
    std::shared_ptr<Farm> m_farm;
    std::shared_ptr<Castle> m_castle;


    //each farm correspond to a castle
    std::queue<std::shared_ptr<Farm>> farms;    //list of farms to load
    std::queue<std::shared_ptr<Castle>> castles;  //list of castles to unload


    int carried_crates;  //number of crates the peasant is carrying
    bool loading;    //this flag tells if peasant is heading towards farm
    void nextPair();

public:
    Peasant(const std::string &name, Point &position);
    void start_working(
        const std::shared_ptr<Farm>& farm,
        const std::shared_ptr<Castle>& castle);
    void update() override;
    void broadcast_current_state() const noexcept override;
    void setCarriedCrates(int cc);
    int getCarriedCrates() const;
    void stop() override;

};

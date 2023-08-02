#pragma once

#include <string>
#include <memory>
#include "Agent.h"
#include "Farm.h"
#include "Castle.h"

class Peasant : public Agent 
{
    Peasant(std::string& name, Point& position);
    shared_ptr<Farm> _farm;
	shared_ptr<Castle> _castle;
	int carried_crates;
    bool is_working;
	
	public:
    static shared_ptr<Peasant> getInstance(std::string& name,Point& position);
	void start_working(shared_ptr<Farm> farm, shared_ptr<Castle> castle  );	// make him pick up hay from his village and go to his castle
	void update() override;

    int getCarriedCrates() const;

    bool isWorking() const;

    void setFarm(const shared_ptr<Farm> &farm);

    void setCastle(const shared_ptr<Castle> &castle);

    void setCarriedCrates(int carriedCrates);

    void setIsWorking(bool isWorking);
};

int Peasant::getCarriedCrates() const {
    return carried_crates;
}

bool Peasant::isWorking() const {
    return is_working;
}

void Peasant::setFarm(const shared_ptr<Farm> &farm) {
    _farm = farm;
}

void Peasant::setCastle(const shared_ptr<Castle> &castle) {
    _castle = castle;
}

void Peasant::setCarriedCrates(int carriedCrates) {
    carried_crates = carriedCrates;
}

void Peasant::setIsWorking(bool isWorking) {
    is_working = isWorking;
}

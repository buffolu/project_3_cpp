#pragma once

#include <string>
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
};

int Peasant::getCarriedCrates() const {
    return carried_crates;
}

bool Peasant::isWorking() const {
    return is_working;
}

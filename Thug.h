#pragma once

#include "Agent.h"

class Thug : public Agent 
{

	private:
    void attack();	// check if there is a peasant nearby to attack

		void update() override;

public:
    Thug(std::string& name_,Point& position);
};




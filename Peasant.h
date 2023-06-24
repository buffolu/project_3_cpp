#pragma once

#include <string>
#include "Agent.h"

class Peasant : public Agent 
{

	std::string home_village;
	std::string home_castle;
	int carried_crates;
	
	public:
    Peasant(std::string& name, Point& position);
	void start_working( const std::string& village, const std::string& castle );	// make him pick up hay from his village and go to his castle
	void update() override;
};

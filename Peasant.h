#pragma once

#include <string>
#include "Agent.h"

class Peasant : public Agent 
{

	std::string& home_village;
	std::string& home_castle;
	
	public:
		void start_working();	// make him pick up hay from his village and go to his castle
		void update() override;
};

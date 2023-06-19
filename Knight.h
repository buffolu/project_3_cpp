#pragma once

#include "Agent.h"
class Knight : public Agent 
{
	
	std::string& home_castle;

	public:
	void update() override;	// check if there is a thug attacking a peasant nearby
};

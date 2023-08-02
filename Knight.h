#pragma once

#include "Agent.h"
class Knight : public Agent
{
    Knight(string basicString, Point point);

    std::string home_castle;

	public:
    static shared_ptr<Knight> getInstance(string& name, Point& p);
	void update() override;	// check if there is a thug attacking a peasant nearby
    void setDestination(string stracture);

};

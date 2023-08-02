#pragma once

#include <memory>
#include "Agent.h"
#include "Structure.h"
#include "list"
class Knight : public Agent
{

    Knight(string &name, Point &position);
    shared_ptr<list<shared_ptr<Structure>>> myStructures;
    list<string> visited;
    std::string home_castle;

    Point destination;

    bool OnCourse;
    bool OnPatrol;
    bool ToPosition;


	public:
    static shared_ptr<Knight> getInstance(string& name, Point& p);
	void update() override;	// check if there is a thug attacking a peasant nearby
    void setDestination(string& structure);

};

//
// Created by igor on 14/06/2023.
//

#ifndef PROJECT_3_AGENT_H
#define PROJECT_3_AGENT_H

#include "Geometry.h"
#include "Sim_object.h"

class Agent : public Sim_object {
	
	Point destination;
	double speed;

	protected:
	enum state {
		STOPPED,
		DEAD,
		MOVING_TO_POSITION
	};
		
	public:
	void move_to_place(Point destination);
	void move_to_direction(double theta);
	void update() override;
	void stop();

};


#endif //PROJECT_3_AGENT_H

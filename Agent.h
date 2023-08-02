//
// Created by igor on 14/06/2023.
//

#ifndef PROJECT_3_AGENT_H
#define PROJECT_3_AGENT_H

#include "Sim_object.h"

class Agent : public Sim_object {

    Point destination;
    double speed;
    int state;
    int health;
    int type;


protected:
    enum state { STOPPED, DEAD, MOVING_TO_POSITION };

    std::string name;
    int angle;
public:
    /**
     * Agent constructor
     *
     * @params
     * -------
     *  name_ : string to name the agent
     *  location : Point to where he spawns
     *  speed_ : how fast he will walk
     *  health : how much health he starts with
     */
    Agent(const std::string &name_, Point location, int speed_, int health);
    void move_to_place(Point &destination_);
    void move_to_direction(double theta);
    void update() override;
    void stop();
    int getType();
    std::string getName();

    const Point &getDestination() const;

    double getSpeed() const;

    int getHealth() const;

    int getState() const;

    void setDestination(const Point &destination);

    void setSpeed(double speed);

    void setState(int state);

    void setHealth(int health);

    void setType(int type);
};

#endif // PROJECT_3_AGENT_H

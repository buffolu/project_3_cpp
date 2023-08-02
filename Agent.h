//
// Created by igor on 14/06/2023.
//

#ifndef PROJECT_3_AGENT_H
#define PROJECT_3_AGENT_H

#include "Sim_object.h"
#include "Structure.h"
#include <memory>

class Agent : public Sim_object {

    double speed;
    int health;

public:
    // always set state destination, destination_coordinates, course together
    enum state { DEFAULT, STOPPED, DEAD, MOVING_TO_POSITION, MOVING_ON_COURSE,ON_DUTY };

private:
    enum state state;
    // can be null to say that agent is moving towards a different place
    std::shared_ptr<Structure> destination;

    // possibly unnecessary
    Point destination_coordinates;
    double course;

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

    void update() override;

    void stop();

    void setCourse(double theta);
    double getCourse() const;

    // possibly unnecessary
    void setDestinationCoordinates(Point destination);
    Point getDestinationCoordinates() const;

    void setDestination(std::shared_ptr<Structure> destination);
    std::shared_ptr<Structure> getDestination() const;

    void setSpeed(double speed);
    double getSpeed() const;

    // void setState(enum state state);
    int getState() const;

    void setHealth(int health);
    int getHealth() const;

    void broadcast_current_state() const noexcept override;


    void setState(enum state state);
};

#endif // PROJECT_3_AGENT_H

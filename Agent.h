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
    enum state { STOPPED, DEAD, MOVING_TO_POSITION, MOVING_ON_COURSE, ON_DUTY };
    /**
     * moving_to_position = user called the "position x,y" command
     * moving_on_course = user called the "course theta" command
     * on_duty = user called one of the methods for specific agent to
     * work(patrol,loading crates,attack, etc... )
     */

private:
    enum state state;

    Point
        destination_coordinates; // used when the user call the position command
    double angle;                // used when the user call the course command

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

    virtual void stop();

    virtual void setCourse(double theta);
    double getCourse() const;

    virtual void setDestinationCoordinates(Point destination);
    Point getDestinationCoordinates() const;

    void setSpeed(double speed);
    double getSpeed() const;

    // void setState(enum state state);
    int getState() const;

    double getAngle() const;

    void setHealth(int health);
    int getHealth() const;

    void broadcast_current_state() const noexcept override;

    void setAngle(double angle);

    void setState(enum state state);
};

#endif // PROJECT_3_AGENT_H

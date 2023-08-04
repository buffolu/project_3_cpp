//
// Created by igor on 14/06/2023.
//

#ifndef PROJECT_3_MODEL_H
#define PROJECT_3_MODEL_H

#include "Agent.h"
#include "Farm.h"
#include "Geometry.h"
#include "Knight.h"
#include "Peasant.h"
#include "Sim_object.h"
#include "Structure.h"
#include "Thug.h"
#include "View.h"
#include "Controller.h"
#include <memory>
#include <string>
#include <vector>

class Model {
    std::shared_ptr<std::vector<std::shared_ptr<Sim_object>>> Sim_object_list;
    std::shared_ptr<std::vector<std::shared_ptr<Structure>>> Structure_list;
    std::shared_ptr<std::vector<std::shared_ptr<Agent>>> Agent_list;
    int time;

public:
    void status(); // broadCast statue of every object
    void go();     // update every object in one time step

    // add agents
    void addKnight(const std::string &name, const std::string &home);
    void addPeasant(const std::string &name, Point position);
    void addThug(const std::string &name, Point position);

    // add structures
    void addFarm(std::string);
    void addCastle(std::string);

    // getters
    // setters
    void attach();
    void detach();
    void notify_Location();

    // methods for model
    void run(int argc, char **argv);

    // ralevent to diffrent kind of agents
    void course(string &basicString, double theta, int i);
    void position(string &basicString, Point point, int i);
    void stop(string &basicString);

    // each method is relavant to only one kind of agent
    void attack(std::string &thug, std::string &peasant);
    void start_working(string &peasant_name, string &farm_name, string &castle);
    void destination(string &knight_name, string &basicString1);

    // finders
    inline shared_ptr<Agent> findAgent(const std::string &name);
    shared_ptr<Structure> findStructure(const string &basicString);

    void badInput(const std::string &);

private: // Singleton
    Model() : time(0){};
    Model(const Model&) = delete;
    Model &operator=(const Model&) = delete;

public:
    static Model &Get();
};

#endif // PROJECT_3_MODEL_H

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
#include <vector>
#include <memory>
#include <string>

class Model {
    std::vector<std::shared_ptr<Sim_object>> Sim_object_list;
    std::vector<std::shared_ptr<Structure>> Structure_list;
    std::vector<std::shared_ptr<Agent>> Agent_list;
    std::unique_ptr<View> m_view;
    std::unique_ptr<Controller> m_controller;
    int time;
    enum type { KNIGHT, PEASANT, THUG };

public:
    void update();
    void addAgent(std::string &name, int type, Point &position, int speed);

    void attack(std::string &thug, std::string &peasant);

    // getters
    // setters
    void attach();
    void detach();
    void notify_Location();

    bool check_if_starcture_exists(string &name);

    bool check_if_exists(string &name);

    // methods for model
    void status();

    void go();
    void run(int argc, char **argv);

    void course(string &basicString, int i, double i1);

    void position(string &basicString, Point point, int i);

    void destination(string &basicString, string &basicString1);

    void stop(string &basicString);

    // methods for view
    void ddefault();

    void setSize(int i);

    void zoom(int i);

    void start_working(string &peseant_name, string &farm_name, string &castle);

    shared_ptr<Agent> findAgent(std::string &name, int type);

    shared_ptr<Structure> findStrcture(string &basicString);

    void badInput(const std::string&);
    
private: // Singleton
    Model() : time(0){};
public:
    static Model& Get();
};

#endif // PROJECT_3_MODEL_H

//
// Created by igor on 14/06/2023.
//
#include <list>
#include "View.h"
#include "Structure.h"
#include <memory>
#include "Thug.h"
#include "Knight.h"
#include "Peasant.h"

#ifndef PROJECT_3_MODEL_H
#define PROJECT_3_MODEL_H

class Model {
    std::list<shared_ptr<Sim_object>> Sim_object_list;
    std::list<weak_ptr<Sim_object>> Stracture_list;
    std::list<weak_ptr<Sim_object>> Agent_list;
    std::list<unique_ptr<View>> View_list;
    int time;
    enum type{
        KNIGHT,
        PEASANT,
        THUG
    };


public:
    Model():time(0){};
    void update();
    void addAgent(std::string & name, int type,Point & position);
    void attack(std::string& thug,std::string& peasant);

    //getters
    //setters
    void attach();
    void detach();
    void notify_Location();

    bool check_if_agent_exists(string &name);
    bool check_if_starcture_exists(string& name);

    bool check_if_exists(string &name);
};


#endif //PROJECT_3_MODEL_H

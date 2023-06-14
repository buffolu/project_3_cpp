//
// Created by igor on 14/06/2023.
//
#include <list>
#include "Strucute.h"
#include "Sim_object.h"
#include "Agent.h"
#include "View.h"

#ifndef PROJECT_3_MODEL_H
#define PROJECT_3_MODEL_H

template <class T>
class Model {
    std::list<Sim_object> Sim_object_list;
    std::list<Strucute> Stracture_list;
    std::list<Agent> Agent_list;
    std::list<View> View_list;
public:
    void update();
    void addAgent();
    //getters
    //setters
    void attach();
    void detach();
    void notify_Location();

};


#endif //PROJECT_3_MODEL_H

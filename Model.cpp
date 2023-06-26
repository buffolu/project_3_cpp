//
// Created by igor on 14/06/2023.
//

#include "Model.h"

void Model::update() {
    for (const auto& object:Sim_object_list){
        (*object).update();

    }
    for( auto& views:View_list){
        (*views).update_location();
    }
    time++;

}


void Model::addAgent(std::string &name, std::string& type,Point& position) {
    if(type == "thug") {
        std::shared_ptr<Sim_object> sharedAgent(new Thug(name,position));
        std::weak_ptr<Sim_object> weakAgent(sharedAgent);


        Sim_object_list.push_back(sharedAgent);
        Agent_list.push_back(weakAgent);
    }
    else if (type == "peasant"){
        std::shared_ptr<Sim_object> sharedAgent(new Peasant(name,position));
        std::weak_ptr<Sim_object> weakAgent(sharedAgent);


        Sim_object_list.push_back(sharedAgent);
        Agent_list.push_back(weakAgent);

    }
    else if(type == "knight"){
        std::shared_ptr<Sim_object> sharedAgent(new Knight(name,position));
        std::weak_ptr<Sim_object> weakAgent(sharedAgent);


        Sim_object_list.push_back(sharedAgent);
        Agent_list.push_back(weakAgent);
    }
}

void Model::attack(string &thug, string &peasant) {

}

bool Model::check_if_starcture_exists(string &name) {
   for(auto stract:Stracture_list){
       if (auto locked = stract.lock()){
       }
   }
}
bool Model::check_if_agent_exists(string &name) {
    return false;
}

void Model::status() {

}

void Model::go() {

}

void Model::course(string basicString, int i, int i1) {

}

void Model::position(string basicString, Point point, int i) {

}

void Model::destination(string basicString, basic_string<char> &basicString1) {

}

void Model::stop(string basicString) {

}

void Model::addAgent(string &name, string &type) {

}



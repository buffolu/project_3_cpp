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


void Model::addAgent(std::string &name, int type,Point& position) {
    if(type == THUG) {
        std::shared_ptr<Sim_object> sharedAgent(new Thug(name,position));
        std::weak_ptr<Sim_object> weakAgent(sharedAgent);


        Sim_object_list.push_back(sharedAgent);
        Agent_list.push_back(weakAgent);
    }
    if (type == PEASANT){
        std::shared_ptr<Sim_object> sharedAgent(new Peasant(name,position));
        std::weak_ptr<Sim_object> weakAgent(sharedAgent);


        Sim_object_list.push_back(sharedAgent);
        Agent_list.push_back(weakAgent);

    }
    if(type == KNIGHT){
        std::shared_ptr<Sim_object> sharedAgent(new Knight(name,position));
        std::weak_ptr<Sim_object> weakAgent(sharedAgent);


        Sim_object_list.push_back(sharedAgent);
        Agent_list.push_back(weakAgent);
    }
    else{
        throw std::invalid_argument("invalid input");
    }
}

//function not complete , need to send thug to attack peasant
void Model::attack(string &thug, string &peasant) {
    //find if thug exists
    shared_ptr<Agent> thug_ = findAgent(thug, (string &) "thug");
    if (!thug_){
        //illegal argument - peasant does not exists
    }

    //find if peasant exists
    shared_ptr<Agent> peasant_ = findAgent(peasant, (string &) "peasant");
    if (!peasant_){
        //illegal argument - peasant does not exists
    }

    //find location of thug (maybe not needed?)
    Point thug_loc = thug_->getLocation();
    //find location of peasant
    Point peasant_loc = peasant_->getLocation();

        //optional: let thug have pointer to peasant to check his location every turn

    //sent thug to peasant
}

bool Model::check_if_starcture_exists(string &name) {
	for(auto stract:Stracture_list){

		if (auto locked = stract.lock()){
		}
	}

}

void Model::status() {

}

void Model::go() {

}

void Model::course(string& basicString, int i, int i1) {

}

void Model::position(string& basicString, Point point, int theta) {

}

void Model::destination(string& basicString, basic_string<char> &basicString1) {

}

void Model::stop(string& basicString) {

}

void Model::ddefault() {
    View_list.front()->ddefault();
}

void Model::setSize(int i) {
    View_list.front()->setSize(i);
}

void Model::zoom(int i) {
    View_list.front()->setSize(i);
}

shared_ptr<Agent> Model::findAgent(std::string& name, std::string &type) {
    for(auto & it : Agent_list)
    {
        if (it->getName() == name && it->getType() == type){
            return it;
        }
    }

    return nullptr;
}


//
// Created by igor on 14/06/2023.
//

#include "Model.h"
#include <fstream>

void Model::run(int argc, char **argv) {
    // SETUP
    if (argc != 3) {
        m_view->Log(std::string("Usage: ") + argv[0] +
                    " <castles.dat> <farms.dat>");
    }
    std::ifstream if_castles(argv[1]);
    std::ifstream if_farms(argv[2]);

    std::string castle;
    while (if_castles >> castle) {
        // TODO: AddCastle(castle);
    }
    if_castles.close();
    std::string farm;
    while (if_farms >> farm) {
        // TODO: AddFarm(farm);
    }
    if_farms.close();

    // TODO
}

void Model::update() {
    for (const auto &object : Sim_object_list) {
        (*object).update();
    }
    time++;
}

void Model::addAgent(std::string &name, int type, Point &position, int speed) {
    std::shared_ptr<Agent> sharedAgent;
    if (type == THUG) {
        sharedAgent = Thug::getThug(name, position, speed);
    } else if (type == PEASANT) {
        sharedAgent = Peasant::getInstance(name, position);
    } else if (type == KNIGHT) {
        sharedAgent = Knight::getInstance(name, position);
    } else {
        throw std::invalid_argument("invalid input");
    }
    Sim_object_list.push_back(sharedAgent);
    Agent_list.push_back(sharedAgent);
}

// function not complete , need to send thug to attack peasant
void Model::attack(string &thug, string &peasant) {
    // find if thug exists
    shared_ptr<Agent> thug_ = findAgent(thug, THUG);
    shared_ptr<Thug> thug1 = dynamic_pointer_cast<Thug>(thug_);
    if (!thug_ || !thug1) {
        // illegal argument - peasant does not exists
    }

    // find if peasant exists
    shared_ptr<Agent> peasant_ = findAgent(peasant, PEASANT);
    if (!peasant_) {
        // illegal argument - peasant does not exists
    }
    thug1->attack(dynamic_pointer_cast<Peasant>(peasant_));
}

/* unnecessary, use container method Structure_list->find_if();
shared_ptr<Structure> Model::check_if_sturcture_exists(string &name) {
    for (auto &it : Structure_list) {
        if (it->getName() == name) {
            return it;
        }
    }
}
*/

void Model::status() {}

void Model::go() {}

void Model::course(const string &basicString, int i, int i1) {}

void Model::position(string &basicString, Point point, int theta) {}

void Model::destination(string &basicString, basic_string<char> &basicString1) {

}

void Model::stop(string &basicString) {}

// void Model::ddefault() { m_view->ddefault(); }

void Model::setSize(int i) { m_view->setSize(i); }

void Model::zoom(int i) { m_view->setSize(i); }

shared_ptr<Agent> Model::findAgent(std::string &name, int type) {
    for (auto &it : Agent_list) {
        if (it->getName() == name && (type == it->getType()) || type == -1) {
            return it;
        }
    }
    return nullptr;
}

void Model::badInput(const std::string& str) {
    std::string badInputMessage = std::string("Bad input: \"") + str + "\"";
    m_view->Log(badInputMessage);
}

Model &Model::Get() {
    static Model instance;
    return instance;
}

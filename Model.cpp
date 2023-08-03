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

void Model::go() {
    for (const auto &object : *Agent_list) {
        object->update();
    }
    time++;
}

void Model::addKnight(const std::string &name, const std::string &home) {
   auto it = findStrcture(home,CASTLE);
   if(!it) {
       throw exception();
   }
    double x = it->getLocation().x;
    double  y = it->getLocation().y;


    std::shared_ptr<Knight> knight = std::make_shared<Knight>(name,Point(x,y));
    Sim_object_list->push_back(knight);
    Agent_list->push_back(knight);
}

void Model::addPeasant(const std::string& name, Point position) {
    std::shared_ptr<Peasant> peasant = std::make_shared<Peasant>(name, position);
    Sim_object_list->push_back(peasant);
    Agent_list->push_back(peasant);
}

void Model::addThug(const std::string &name, Point position) {
    std::shared_ptr<Thug> thug = std::make_shared<Thug>(name, position);
    Sim_object_list->push_back(thug);
    Agent_list->push_back(thug);
}

void Model::addAgent(const std::string &name,int type, Point &position,const std::string& home) {
    if(findAgent(name,-1)) {throw exception();} //agent already exists.

    if (type == THUG) {
        addThug(name,position);
    } else if (type == PEASANT) {
        addPeasant(name,position);
    } else if (type == KNIGHT) {
        addKnight(name,home);}
     else{
        throw std::invalid_argument("invalid input");
    }

}



shared_ptr<Structure> Model::findStructure(const string &name,int type)
 {
    auto it = find_if(Structure_list->begin(),Structure_list->end(),[&name,type] (shared_ptr<Structure>& structure) {return
    name== structure->getName() && (structure->getType == type || type == -1);
    });
    if(it != Structure_list->end())
    {
        return *it;
    }
    return nullptr;
}

void Model::status() {
    for(const auto& obj: *Sim_object_list)
    {
        obj->broadcast_current_state();
    }
}


void Model::course(string &basicString,double theta) {

    auto agent = findAgent(basicString,-1);
    if(agent && agent.getType() != PEASANT) {
        agent->setCourse(theta);
    }
    else
    {
        /*
         * TODO: THROW EXCPETION OR IGNORE
         */
    }

}

void Model::position(string &basicString, Point point) {
    auto agent = findAgent(basicString,-1);
    if(agent && agent.getType() != PEASANT) {
        agent->setDestinationCoordinates(point);
    }
    else
    {
        /*
         * TODO: THROW EXCPETION OR IGNORE
         */
    }
}



void Model::stop(string &basicString) {
    auto agent = findAgent(basicString,-1);
    if(agent) {
        agent->stop();
    }
    else
    {
        /*
         * TODO: THROW EXCPETION OR IGNORE
         */
    }
}
void Model::destination(string &basicString, string& castle) {
    auto agent = findAgent(basicString, KNIGHT);
    auto castle_ = findStructure(castle,-1);
    if (castle_ && castle_ && !agent) //castle or agent does not exist
    {

        shared_ptr<Knight> knight = dynamic_pointer_cast<Knight>(agent);
        knight->setOnPatrol(castle_,Structure_list);
    }
    else
    {
        /*
          * TODO: THROW EXCPETION OR IGNORE
          */
    }
}

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
    thug1->attack(dynamic_pointer_cast<Peasant>(peasant_),Agent_list);
}



shared_ptr<Agent> Model::findAgent(const std::string &name, int type) {
    for (auto &it : *Agent_list) {
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

void Model::start_working(string &peasant_name, string &farm_name, string &castle_name) {
    auto agent = findAgent(peasant_name,PEASANT);
    auto structure1 = findStrcture(farm_name,FARM);
    auto structure2  = findStrcture(castle_name,CASTLE);
    if(agent && structure1 && structure2)
    {
        shared_ptr<Peasant> peasant = dynamic_pointer_cast<Peasant>(agent);
        shared_ptr<Farm>    farm  = dynamic_pointer_cast<Farm>(structure1);
        shared_ptr<Castle>  castle  = dynamic_pointer_cast<Castle>(structure1);

        peasant->start_working(farm,castle);

    }
    else{
        /*
      * TODO: THROW EXCPETION OR IGNORE
      */
    }

}





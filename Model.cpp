//
// Created by igor on 14/06/2023.
//

#include "Model.h"

std::unique_ptr<Model> Model::model = nullptr;

void Model::go() {
    for (const auto &object : *Sim_object_list) {
        object->update();
    }
    time++;
}

//add a new knight
void Model::addKnight(const std::string &name, const std::string &home) {
    if (findAgent(name)) {
        log(name + " already exists");
        return;
    }

    auto it = findStructure(home);
    if (!it) {
        log(home + " structure doesn't exist");
        return;
    }

    std::shared_ptr<Castle> p_castle = std::dynamic_pointer_cast<Castle>(it);
    if (!p_castle) {
        log(home + " is not a castle");
        return;
    }
    double x = it->getLocation().x;
    double y = it->getLocation().y;

    std::shared_ptr<Knight> knight =
        std::make_shared<Knight>(name, Point(x, y));

    Sim_object_list->push_back(knight);
    Agent_list->push_back(knight);
}

//add a new peasant
void Model::addPeasant(const std::string &name, Point position) {
    if (findAgent(name)) {
        log(name + " already exists");
        return;
    }

    std::shared_ptr<Peasant> peasant =
        std::make_shared<Peasant>(name, position);

    Sim_object_list->push_back(peasant);
    Agent_list->push_back(peasant);
}

//add a new thug
void Model::addThug(const std::string &name, Point position) {
    if (findAgent(name)) {
        log(name + " already exists");
        return;
    }

    std::shared_ptr<Thug> thug = std::make_shared<Thug>(name, position);

    Sim_object_list->push_back(thug);
    Agent_list->push_back(thug);
}
//find structure in my world and return pointer, otherwise return nullptr
std::shared_ptr<Structure> Model::findStructure(const std::string &name) {
    auto it = find_if(Structure_list->begin(), Structure_list->end(),
                      [&name](std::shared_ptr<Structure> &structure) {
                          return name == structure->getName();
                      });
    if (it != Structure_list->end()) {
        return *it;
    }
    return nullptr;
}
//print status of every object
void Model::status() {
    for (const auto &obj : *Sim_object_list) {
        obj->broadcast_current_state();
        std::cout << std::endl;
    }
}

//set course for agent to do using an angle and speed (usefull for thug)
void Model::course(const std::string &basicString, double theta, int speed) {

    if (speed <= 0) {
        badInput("speed must be positive");
        return;
    } else if (speed > 30) {
        badInput("speed cant be bigger than 30");
        return;
    }

    auto agent = findAgent(basicString);
    std::shared_ptr<Thug> thug = std::dynamic_pointer_cast<Thug>(agent);
    if (thug) {
        thug->setCourse(theta);
        thug->setSpeed(speed);
    } else {
        m_view->Log("No thug named " + basicString);
    }
}
//same as before without speed
void Model::course(const std::string &basicString, double theta) {

    auto agent = findAgent(basicString);
    if (agent && !std::dynamic_pointer_cast<Peasant>(agent)) {
        agent->setCourse(theta);
    } else {
        m_view->Log("No agent named " + basicString);
    }
}

//set agent to a position in map (x, y) and set his speed (only works for thug)
void Model::position(const std::string &basicString, Point point, int speed) {
    auto agent = findAgent(basicString);
    if (agent && std::dynamic_pointer_cast<Thug>(agent)) {
        agent->setDestinationCoordinates(point);
        agent->setSpeed(speed);
    } else {
        m_view->Log("No agent named " + basicString);
    }
}
//same as the previous without speed
void Model::position(const std::string &basicString, Point point) {
    auto agent = findAgent(basicString);
    if (agent && (std::dynamic_pointer_cast<Peasant>(agent) ||
                  std::dynamic_pointer_cast<Knight>(agent))) {
        agent->setDestinationCoordinates(point);
    } else {
        m_view->Log("No agent named " + basicString);
    }
}
//stop an agent that is not dead
void Model::stop(const std::string &basicString) {
    auto agent = findAgent(basicString);
    if (agent) {
        agent->stop();
    } else {
        m_view->Log("No agent named " + basicString);
    }
}

//set destination using a structure,only works for knight
void Model::destination(const std::string &basicString,
                        const std::string &castle) {
    auto agent = findAgent(basicString);
    auto castle_ = findStructure(castle);
    if (!castle_) {
        badInput("No structure named " + castle);
        return;
    }
    if (!agent) {
        badInput("No agent named " + basicString);
        return;
    }
    std::shared_ptr<Knight> knight = std::dynamic_pointer_cast<Knight>(agent);

    if (knight ) {
        knight->setOnPatrol(castle_, Structure_list);
    } else {
        badInput(basicString + " not a knight\n");
    }
}

//attack a peasant , only works for thug
void Model::attack(const std::string &thug, const std::string &peasant) {
    // find if thug exists
    std::shared_ptr<Agent> thug_ = findAgent(thug);
    std::shared_ptr<Thug> thug1;
    if (thug_) {
        thug1 = std::dynamic_pointer_cast<Thug>(thug_);
        if (!thug1) {
            m_view->Log(thug + " is not a thug");
            return;
        }
    } else {
        m_view->Log("No agent named " + thug);
        return;
    }

    // find if peasant exists
    std::shared_ptr<Agent> peasant_ = findAgent(peasant);
    if (!peasant_) {
        m_view->Log("No agent named " + peasant);
        return;
    }
    std::shared_ptr<Peasant> peasant1 =
        std::dynamic_pointer_cast<Peasant>(peasant_);
    if (!peasant1) {
        m_view->Log(peasant + " is not a peasant");
        return;
    }
    thug1->attack(peasant1, Agent_list);
}

//find agent and return pointer, otherwise return nullptr
std::shared_ptr<Agent> Model::findAgent(const std::string &a_name) {
    auto it = std::find_if(Agent_list->begin(), Agent_list->end(),
                           [a_name](std::shared_ptr<Agent> &agent) {
                               return agent->getName() == a_name;
                           });
    if (it != Agent_list->end()) {
        return *it;
    }
    return nullptr;
}

void Model::badInput(const std::string &str) {
    std::string badInputMessage = std::string("Bad input: \"") + str + "\"";
    m_view->Log(badInputMessage);
}

//make peasant start working and loading and unloading from farm to castle
void Model::start_working(const std::string &peasant_name,
                          const std::string &farm_name,
                          const std::string &castle_name) {
    auto _agent = findAgent(peasant_name);
    auto _farm = findStructure(farm_name);
    auto _castle = findStructure(castle_name);
    if (_agent && _farm && _castle) {
        std::shared_ptr<Peasant> peasant =
            std::dynamic_pointer_cast<Peasant>(_agent);
        std::shared_ptr<Farm> farm =
            std::dynamic_pointer_cast<Farm>(_farm);
        std::shared_ptr<Castle> castle =
            std::dynamic_pointer_cast<Castle>(_castle);
        if (peasant && _farm && _castle) {
            peasant->start_working(farm, castle);
        }

        else {
            m_view->Log("Invalid name");
        }

    } else {
        m_view->Log("Invalid name");
    }
}
const std::shared_ptr<std::vector<std::shared_ptr<Sim_object>>> &
Model::getSimObjectList() const {
    return Sim_object_list;
}

//methods for view
void Model::makeDefault() { m_view->makeDefault(); }

void Model::setSizeView(int _size) { m_view->setSize(_size); }

void Model::setZoomView(double zoom) { m_view->setScale(zoom); }

void Model::setPanView(double x, double y) { m_view->setPan(x, y); }

void Model::show() { m_view->show(); }

void Model::attach(std::unique_ptr<View> someView) {
    if (!m_view) {
        m_view = std::move(someView);
    }
}

void Model::detach(std::unique_ptr<View> someView) {
    if (someView == m_view) {
        m_view.reset();
    }
}

//add a new farm with a unique name
void Model::addFarm(const std::string &line) {
    std::vector<std::string> &&separated = utils::split(line, ',');
    std::string &name = separated[0];
    std::string &xstr = separated[1];
    std::string &ystr = separated[2];
    std::string &hay = separated[3];
    std::string &prod = separated[4];

    if (findStructure(name)) {
        log(name + " already exists");
        throw std::invalid_argument("a structure with similar name exists");
    }

    xstr = xstr.substr(2);                    // to cut off " ("
    ystr = ystr.substr(0, ystr.length() - 1); // to cut off ")"

    double x = std::stod(xstr);
    double y = std::stod(ystr);

    int nhay = std::stoi(hay);

    int production = std::stoi(prod);

    std::shared_ptr<Farm> farm =
        std::make_shared<Farm>(name, Point(x, y), nhay, production);
    Structure_list->push_back(farm);
    Sim_object_list->push_back(farm);
}
//add a new castle with a unique name
void Model::addCastle(const std::string &line) {
    std::vector<std::string> &&separated = utils::split(line, ',');
    std::string &name = separated[0];
    std::string &xstr = separated[1];
    std::string &ystr = separated[2];
    std::string &hay = separated[3];

    if (findStructure(name)) {
        log(name + " already exists");
        throw std::invalid_argument("a structure with similar name exists");
    }

    xstr = xstr.substr(2);                    // to cut off " ("
    ystr = ystr.substr(0, ystr.length() - 1); // to cut off ")"

    double x = std::stod(xstr);
    double y = std::stod(ystr);

    int nhay = std::stoi(hay);

    std::shared_ptr<Castle> castle =
        std::make_shared<Castle>(name, Point(x, y), nhay);
    Structure_list->push_back(castle);
    Sim_object_list->push_back(castle);
}

void Model::log(const std::string &str) { m_view->Log(str); }

Model &Model::Get() {
    if (!model) {
        model = std::unique_ptr<Model>(new Model());
    }
    return *model;
}

Model::Model() : time(0) {
    Sim_object_list =
        std::make_shared<std::vector<std::shared_ptr<Sim_object>>>();
    Structure_list =
        std::make_shared<std::vector<std::shared_ptr<Structure>>>();
    Agent_list = std::make_shared<std::vector<std::shared_ptr<Agent>>>();
    m_view = std::make_unique<View>();
    m_view->addObjects(Sim_object_list);
}

const int &Model::getTime() { return time; };

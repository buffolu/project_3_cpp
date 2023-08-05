//
// Created by igor on 14/06/2023.
//

#ifndef PROJECT_3_MODEL_H
#define PROJECT_3_MODEL_H
#include "Agent.h"
#include "Castle.h"
#include "Farm.h"
#include "Knight.h"
#include "Peasant.h"
#include "Sim_object.h"
#include "Structure.h"
#include "Thug.h"
#include "View.h"

#include "utils.h"

#include <algorithm>
#include <memory>
#include <vector>

class Model {
    std::shared_ptr<std::vector<std::shared_ptr<Sim_object>>> Sim_object_list;
    std::shared_ptr<std::vector<std::shared_ptr<Structure>>> Structure_list;
    std::shared_ptr<std::vector<std::shared_ptr<Agent>>> Agent_list;
    int time;

    std::unique_ptr<View> m_view;

    bool exitflag = false;

public:
    void status(); // broadCast statue of every object
    void go();     // update every object in one time step

    // add agents
    void addKnight(const std::string &name, const std::string &home);
    void addPeasant(const std::string &name, Point position);
    void addThug(const std::string &name, Point position);

    // add structures
    void addFarm(const std::string &);
    void addCastle(const std::string &);

    const std::shared_ptr<std::vector<std::shared_ptr<Sim_object>>> &
    getSimObjectList() const;

    // attach detach view
    void attach(std::unique_ptr<View> someView);
    void detach(std::unique_ptr<View> someView);


    // ralevent to diffrent kind of agents
    void course(const std::string &basicString, double theta, int speed);
    void course(const std::string &basicString, double theta);
    void position(const std::string &basicString, Point point, int speed);
    void position(const std::string &basicString, Point point);
    void stop(const std::string &basicString);

    // each method is relavant to only one kind of agent
    void attack(const std::string &thug, const std::string &peasant);
    void start_working(const std::string &peasant_name,
                       const std::string &farm_name, const std::string &castle);
    void destination(const std::string &knight_name,
                     const std::string &basicString1);

    // finders
    inline std::shared_ptr<Agent> findAgent(const std::string &name);
    std::shared_ptr<Structure> findStructure(const std::string &basicString);

    void badInput(const std::string &);

    // view methods
    void makeDefault();
    void setSizeView(int _size);
    void setZoomView(double zoom);
    void setPanView(double x, double y);
    void show();
    void log(const std::string& str);
    Model(const Model &) = delete;
    Model &operator=(const Model &) = delete;

private: // Singleton
    Model();

public:
    static Model &Get();
    static std::unique_ptr<Model> model;

    const int & getTime();
};

#endif // PROJECT_3_MODEL_H

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
#include <vector>
#include <memory>
#include <string>
#include "View.h"

class Model {
    shared_ptr<  std::vector<std::shared_ptr<Sim_object>> > Sim_object_list;
    shared_ptr<  std::vector<std::shared_ptr<Structure>> > Structure_list;
    shared_ptr<  std::vector<std::shared_ptr<Agent>> > Agent_list;

    std::vector<shared_ptr<View>> views;
    shared_ptr<View>  current_view;

    int time;
    enum type { KNIGHT, PEASANT, THUG,CASTLE,FARM };


public:

    void status(); //broadCast statue of every object
    void go();    //update every object in one time step

    //add agents
    void addAgent(const string &name, int type, Point &position);
    void addAgent(const string &name, int type, std::string& structure);



    const shared_ptr<std::vector<std::shared_ptr<Sim_object>>> &getSimObjectList() const;


    // getters
    // setters
    void attach(shared_ptr<View> someView);
    void detach(shared_ptr<View> someView);



    // methods for model

    void run(int argc, char **argv);


    //ralevent to diffrent kind of agents
    void course(string &basicString, double theta, int i);
    void position(string &basicString, Point point, int i);
    void stop(string &basicString);


    //each method is relavant to only one kind of agent
    void attack(std::string &thug, std::string &peasant);
    void start_working(string &peasant_name, string &farm_name, string &castle);
    void destination(string &knight_name, string &basicString1);




    void badInput(const std::string&);


    //view methods
    void makeDefault();
    void setSizeView(int _size);
    void setZoomView(double zoom);
    void setPanView(double x , double y);
    void show();

    
private: // Singleton
    Model() : time(0){};
    void addKnight(const std::string &name, const std::string &home);
    void addPeasant(const std::string& name, Point position);
    void addThug(const std::string &name, Point position);


    //finders
    shared_ptr<Agent> findAgent(const std::string &name, int type);
    shared_ptr<Structure> findStructure(const string &basicString,int type);




public:
    static Model& Get();


};

#endif // PROJECT_3_MODEL_H

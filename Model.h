//
// Created by igor on 14/06/2023.
//


#ifndef PROJECT_3_MODEL_H
#define PROJECT_3_MODEL_H

#include <list>
#include <memory>
#include <fstream>
#include "View.h"
#include "Structure.h"
#include "Thug.h"
#include "Knight.h"
#include "Peasant.h"
#include "Geometry.h"
#include "Sim_object.h"
#include "Agent.h"





class Model {
	// TODO: maybe change to map, since then we can just find the proper unit based on name
	// TODO: or maybe change to vector instead of list
	std::list<shared_ptr<Sim_object>> Sim_object_list;
	std::list<shared_ptr<Structure>> Structure_list;
	std::list<shared_ptr<Agent>> Agent_list;
	std::list<shared_ptr<View>> View_list;
	int time;	// what tick we're on
	enum type{
		KNIGHT,
		PEASANT,
		THUG
	};

	Controller m_controller;
	View m_view;

public:     // Singleton
	Model& Get();
private:    
	Model() : time(0) {};
public:
	void run(int argc, char** argv);
	void update();
	void addAgent(std::string & name, int type,Point & position);
	void attack(std::string& thug,std::string& peasant);

	//getters
	//setters
	void attach();
	void detach();
	void notify_Location();

	bool check_if_sturcture_exists(string& name);

	bool check_if_exists(string &name);



	//methods for model
	void status();

	void go();

	void course(string& basicString, int i, int i1);

	void position(string& basicString, Point point, int i);

	void destination(string &basicString, string& &basicString1);

	void stop(string& basicString);

	//methods for view
	void ddefault();

	void setSize(int i);

	void zoom(int i);

	shared_ptr<Agent> findAgent(std::string& name);

};


#endif //PROJECT_3_MODEL_H

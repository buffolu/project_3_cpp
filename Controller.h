//
// Created by igor on 25/06/2023.
//

#ifndef PROJECT_3_CONTROLLER_H
#define PROJECT_3_CONTROLLER_H
#include <utility>
#include <vector>
#include <istream>
#include "Model.h"
#include "View.h"

class Controller {
private:
	// possibly unnecessary for a controller to have knowledge of view
    View view;
    Model * model;
    bool isStringOnlyLetters(const std::string& str) const noexcept ;



public:
    explicit Controller(Model& model1) : model(&model1) {};
    bool GetUserInput(std::string& str);
    void readFile(std::fstream& file);






};


#endif //PROJECT_3_CONTROLLER_H

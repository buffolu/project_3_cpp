//
// Created by igor on 25/06/2023.
//

#ifndef PROJECT_3_CONTROLLER_H
#define PROJECT_3_CONTROLLER_H
#include "Model.h"
#include "View.h"
#include "utils.h"
#include <istream>
#include <memory>
#include <utility>
#include <vector>

class Controller {
public:
    bool GetUserInput();
    // might delete
    // void readFile(std::fstream &file);

    Controller();
};

#endif // PROJECT_3_CONTROLLER_H

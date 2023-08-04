//
// Created by igor on 25/06/2023.
//

#ifndef PROJECT_3_CONTROLLER_H
#define PROJECT_3_CONTROLLER_H

#include "utils.h"
#include "Geometry.h"
#include "Model.h"


#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

class Controller {
public:
    bool GetUserInput();
    // might delete
    // void readFile(std::fstream &file);
    Controller();
    void run(int argc, char **argv);
};

#endif // PROJECT_3_CONTROLLER_H

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
#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>

class Controller {
public:
    bool GetUserInput();
    // might delete
    // void readFile(std::fstream &file);
    Controller();
    void run(int argc, char **argv);
};

#endif // PROJECT_3_CONTROLLER_H

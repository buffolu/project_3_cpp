//
// Created by igor on 25/06/2023.
//

#ifndef PROJECT_3_CONTROLLER_H
#define PROJECT_3_CONTROLLER_H

#include "Geometry.h"
#include "Model.h"
#include "utils.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

class Controller {
    bool exitflag = false;

    bool zoom(const std::vector<std::string> &words);
    bool size(const std::vector<std::string> &words);
    bool pan(const std::vector<std::string> &words);
    bool create(const std::vector<std::string> &words);
    bool course(const std::vector<std::string> &words);
    bool position(const std::vector<std::string> &words);
    bool start_working(const std::vector<std::string> &words);

public:
    Controller();
    bool GetUserInput();
    void run(int argc, char **argv);
};

#endif // PROJECT_3_CONTROLLER_H

//
// Created by igor on 25/06/2023.
//

#ifndef PROJECT_3_CONTROLLER_H
#define PROJECT_3_CONTROLLER_H
#include "Model.h"


class Controller {
public:
    bool GetUserInput();
    // might delete
    // void readFile(std::fstream &file);
    Controller();
    void run(int argc, char **argv);
};

#endif // PROJECT_3_CONTROLLER_H

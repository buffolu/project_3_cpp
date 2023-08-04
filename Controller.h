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
    void readFile(std::fstream &file);

private: // Singleton
    Controller() {}
    Controller(const Controller &other) = delete;
    Controller &operator=(const Controller &other) = delete;

public:
    static Controller &Get();
};

#endif // PROJECT_3_CONTROLLER_H

//
// Created by igor on 25/06/2023.
//

#ifndef PROJECT_3_CONTROLLER_H
#define PROJECT_3_CONTROLLER_H
#include "Model.h"
#include "View.h"
#include "utils.h"
#include <istream>
#include <utility>
#include <vector>
#include <memory>

class Controller {
private:
    // possibly unnecessary for a controller to have knowledge of view
    shared_ptr<View> view;
    std::shared_ptr<Model> model;

public:
    explicit Controller(Model &model1) : model(&model1){};
    bool GetUserInput();
    void readFile(std::fstream &file);
};

#endif // PROJECT_3_CONTROLLER_H

//
// Created by igor on 25/06/2023.
//

#ifndef PROJECT_3_CONTROLLER_H
#define PROJECT_3_CONTROLLER_H
#include <utility>
#include <vector>
#include <iostream>
#include "Model.h"
#include "View.h"

class Controller {
private:
    std::vector<std::string> input_;
    View view;
    Model model;
    bool isStringOnlyLetters(const std::string& str) const noexcept ;



public:
    explicit Controller(Model model1):model(std::move(model1)){};
    void GetInput(std::string& str);






};


#endif //PROJECT_3_CONTROLLER_H

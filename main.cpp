#include "Controller.h"
#include <memory>
#include "Model.h"
#include <iostream>

int main(int argc, char **argv) {
    // std::cout << "Hello, World!" << std::endl;//testhere___
    Model::Get().attach(std::make_unique<View>());
    Controller controller;
    controller.run(argc,argv);
    return 0;
}

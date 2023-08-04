#include "Agent.h"
#include "Model.h"
#include "Sim_object.h"
#include "Structure.h"
#include "Thug.h"
#include <iostream>

int main(int argc, char **argv) {
    // std::cout << "Hello, World!" << std::endl;//testhere___
    Model::Get().attach(std::make_unique<View>());
    Model::Get().attach(std::make_unique<Controller>());
    Model::Get().run(argc, argv);
    return 0;
}

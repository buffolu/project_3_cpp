
#include <memory>
#include "View.h"
#include "Controller.h"


int main(int argc, char **argv) {
    Model::Get().attach(std::make_unique<View>());
    Controller controller;
    controller.run(argc,argv);

    return 0;
}

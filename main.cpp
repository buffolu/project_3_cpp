
#include <memory>
#include "View.h"
#include "Controller.h"


int main(int argc, char **argv) {
    std::unique_ptr<View> view_ptr;
    Model::Get().attach(std::move(view_ptr));
    Controller controller;
    controller.run(argc,argv);

    return 0;
}

//
// Created by igor on 25/06/2023.
//

#include "Controller.h"
void Controller::run(int argc, char **argv) {
    // SETUP
    if (argc != 3) {
        Model::Get().log(std::string("Usage: ") + argv[0] +
                         " <castles.dat> <farms.dat>");
        exit(1);
    }
    std::ifstream if_castles(argv[1]);
    std::ifstream if_farms(argv[2]);

    // setup castles
    std::string castle;
    while (std::getline(if_castles, castle)) {
        Model::Get().addCastle(castle);
    }
    if_castles.close();

    // setup farms
    std::string farm;
    while (std::getline(if_farms, farm)) {
        Model::Get().addFarm(farm);
    }
    if_farms.close();

    // primary loop
    while (!exitflag) {
        GetUserInput();
    }
}

/**
 * true means that the command was sent on to model
 * false means that the command failed to send
 * doesn't do anything else
 */
bool Controller::GetUserInput() {
    std::cout << "Time: " << Model::Get().getTime() << ":Enter command: ";
    std::string input;
    std::getline(std::cin, input);
    if (input == "") {
        Model::Get().badInput(input);
        return 0;
    }

    std::vector<std::string> &&words = utils::split(input, ' ');

    std::string &command = words[0];
    if (command == "exit") {
        exitflag = true;
        return true;
    } else if (command == "default") {
        Model::Get().makeDefault();
        return true;
    } else if (command == "size" && words.size() == 2) {
        return size(words);
    } else if (command == "zoom" && words.size() == 2) {
        return zoom(words);
    } else if (command == "pan" && words.size() == 3) {
        return pan(words);
    } else if (command == "show" && words.size() == 1) {
        Model::Get().show();
        return true;
    }

    // related to model
    else if (command == "status") {
        Model::Get().status();
        return true;
    } else if (command == "go") {
        Model::Get().go();
        return true;
    } else if (command == "create") {
        return create(words);
    }

    if (words.size() < 2) {
        Model::Get().badInput("invalid input");
        return false;
    }

    // this commands will be given after the name.
    // at this point words[0] is a name of an agent
    const std::string name = words[0];

    const std::string &command2 = words[1];

    if (command2 == "course") {
        return course(words);
    }
    if (command2 == "position") {
        return position(words);
    }
    if (command2 == "destination" && words.size() == 3) {
        Model::Get().destination(name, words[2]);
        return true;
    }
    if (command2 == "stop" && words.size() == 2) {
        Model::Get().stop(name);
        return true;
    }
    if (command2 == "attack" && words.size() == 3) {
        std::string peasant = words[2];
        Model::Get().attack(name, peasant);
        return true;
    }
    if (command2 == "start_working" && words.size() == 4) {
        return start_working(words);
    }

    Model::Get().badInput("invalid input");
    return false;
}

Controller::Controller() {}

//the set the zoom of the map
bool Controller::zoom(const std::vector<std::string> &words) {
    if (words.size() != 2)
        return false;
    double num;
    try {
        // this filters words of kind "123KK"
        num = std::stod(words[1]);
    } catch (std::invalid_argument &) {
        Model::Get().badInput("Expected a double");
        return false;
    }

    Model::Get().setZoomView(num);
    return true;
}

//set the size
bool Controller::size(const std::vector<std::string> &words) {
    int num;
    try {
        num = std::stoi(words[1]);
    } catch (std::invalid_argument &) {
        Model::Get().badInput("Expected an integer");
        return false;
    }

    Model::Get().setSizeView(num);

    return true;
}

//set the origin point (down left point)
bool Controller::pan(const std::vector<std::string> &words) {
    double x, y;
    try {
        x = stoi(words[1]);
        y = stoi(words[2]);
    } catch (std::invalid_argument &e) {
        Model::Get().badInput("expected integers");
        return false;
    }
    Model::Get().setPanView(x, y);
    return true;
}

bool Controller::create(const std::vector<std::string> &words) {
    std::string name = words[1];

    std::string typeStr = words[2]; // knight , thug or peasant
    double x, y;

    if (!utils::isStringOnlyLetters(name)) {
        Model::Get().badInput("name expected to be only characters");
        return false;
    }

    if (typeStr == "knight" && words.size() == 4) {
        std::string castle_name = words[3];
        Model::Get().addKnight(name, castle_name);
        return true;
    }
    if (words.size() != 5) {
        Model::Get().badInput("invalid command");
        return false;
    }
    try {
        // cut off the leading '(' and trailing ','
        x = std::stod(words[3].substr(1, words[3].length() - 1));
        // cut off the trailing ')'
        y = std::stod(words[4].substr(0, words[4].length() - 1));
    } catch (std::invalid_argument &e) {
        Model::Get().badInput("expected doubles");
        return false;
    }

    if (typeStr == "peasant") {
        // add peasant
        Model::Get().addPeasant(name, {x, y});
        return true;
    } else if (typeStr == "thug") {
        // add thug
        Model::Get().addThug(name, {x, y});
        return true;
    }

    Model::Get().badInput("invalid command");
    return false;
}

bool Controller::course(const std::vector<std::string> &words) {
    if (words.size() != 3 && words.size() != 4) {
        Model::Get().badInput("improper arguments");
        return false;
    }

    std::string name = words[0];
    double theta = std::stod(words[2]);
    int speed;
    // size is 3 when speed is not given,
    // so knight or peasant
    if (words.size() == 3) {
        Model::Get().course(name, theta);
        return true;
    } else if (!(words.size() == 4)) { // this is for thug
        Model::Get().badInput("improper arguments");
        return false;
    }

    try {
        speed = std::stoi(words[3]);
    } catch (std::invalid_argument &e) {
        Model::Get().badInput("expected integer");
        return false;
    }

    Model::Get().course(name, theta, speed);
    return true;
}

bool Controller::position(const std::vector<std::string> &words) {
    std::string name = words[0];

    double x, y;
    try {
        // cut off the leading '(' and trailing ','
        x = std::stod(words[2].substr(1, words[2].length() - 1));
        // cut off the trailing ')'
        y = std::stod(words[3].substr(0, words[3].length() - 1));
    } catch (std::invalid_argument &e) {
        Model::Get().badInput("expected doubles");
        return false;
    }

    if (words.size() == 4) { // n p x y
        Model::Get().position(name, {x, y});
        return true;
    }
    if (words.size() == 5) { // n p x y s
        int speed;
        try {
            speed = std::stoi(words[4]);
        } catch (std::invalid_argument &e) {
            Model::Get().badInput("expected integer");
            return false;
        }
        Model::Get().position(name, {x, y}, speed);
        return true;
    }
    Model::Get().badInput("bad input");
    return false;
}

bool Controller::start_working(const std::vector<std::string> &words) {
    if (words.size() != 4) { // n s_w f c
        Model::Get().badInput("invalid arguments");
        return false;
    }
    std::string peasant_name = words[0];
    std::string farm_name = words[2];
    std::string castle_name = words[3];

    Model::Get().start_working(peasant_name, farm_name, castle_name);

    return true;
}

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

    std::string castle;
    while (std::getline(if_castles, castle)) {
        Model::Get().addCastle(castle);
    }
    if_castles.close();
    std::string farm;
    while (std::getline(if_farms, farm)) {
        Model::Get().addFarm(farm);
    }
    if_farms.close();
    while (!exitflag) {
        GetUserInput();
    }
}

bool Controller::GetUserInput() {
    std::string input;
    if (std::getline(std::cin, input)) {
        if (input == "") {
            Model::Get().badInput(input);
            return 0;
        }
    }

    std::vector<std::string> &&words = utils::split(input, ' ');

    try {
        // lines 22-54  inputs related to view
        if (words.empty()) {
            throw std::invalid_argument("invalid input");
        }

        std::string command = words.front();
        words.erase(words.begin());
        if (command == "exit" && words.empty()) {
            exitflag = true;
        } else if (command == "default" && words.empty()) {
            Model::Get().makeDefault();

        } else if (command == "size" && words.size() == 1) {
            int s = std::stoi(words.back());
            if (s > 6 && s <= 30) {
                Model::Get().setSizeView(s);
            } else {
                throw std::invalid_argument("invalid input");
            }
        } else if (command == "zoom" && words.size() == 1) {
            double num = std::stoi(words.back());
            if (num > 0) {
                Model::Get().setZoomView(num);
            }

            else {
                throw std::invalid_argument("invalid input");
            }

        }

        else if (command == "pan" && words.size() == 2) {
            words.erase(words.begin());
            double x = stoi(words.front());
            double y = stoi(words.back());
            Model::Get().setPanView(x, y);
        } else if (command == "show" && words.empty()) {
            Model::Get().show();
        }

        // line 59- related to model
        else if (command == "status" && words.empty()) {
            Model::Get().status();
        } else if (command == "go" && words.empty()) {
            Model::Get().go();
        } else if (command == "create" &&
                   (words.size() == 3 || words.size() == 4)) {
            std::string name = words.front();
            words.erase(words.begin());
            std::string typeStr = words.front(); // knight , thug or peasant
            std::transform(typeStr.begin(), typeStr.end(), typeStr.begin(),
                           [](char c) { return std::tolower(c); });
            words.erase(words.begin());
            if (!utils::isStringOnlyLetters(name)) {
                throw std::invalid_argument("invalid input");
            }

            if (words.size() == 2 && words.front().size() == 3 &&
                words.back().size() == 2) // coordination in the form of (x,
                                          // y)-thug or peasant or knight.
            {
                std::string word1 =
                    words.front(); // should be in the form of (x,
                word1 = word1.substr(1);
                word1.pop_back();
                double x = std::stoi(word1);
                std::string word2 = words.back();
                word2.pop_back();
                double y = std::stoi(word2);
                Point p(x, y);

                if (typeStr == "peasant") {
                    // add peasant
                    Model::Get().addPeasant(name, p);
                } else if (typeStr == "thug") {
                    // add thug
                    Model::Get().addThug(name, p);
                } else {
                    throw std::invalid_argument(
                        "a point is given to thug or peasant");
                }
            } else if (words.size() == 1) {
                std::string structure = words.front();
                if (typeStr == "knight") {
                    Model::Get().addKnight(name, structure);
                } else { // how does a not knight get here ??
                }
            }
        }
        // this commands will be given after the name.
        std::string name = std::move(command);
        words.erase(words.begin());
        if (words.empty()) {
            throw std::invalid_argument("invalid input");
        }

        std::string command2 = words.front();
        words.erase(words.begin());

        if (command2 == "course" && (words.size() == 1 || words.size() == 2)) {
            std::string word1 = words.front();
            int theta = std::stoi(word1);
            int speed = -1;
            if (words.size() > 1) {
                std::string word2 = words.back();
                speed = std::stoi(word2);
                if (speed <= 0) {
                    throw std::invalid_argument("invalid input");
                }
            }
            Model::Get().course(name, theta, speed);
        }
        if (command2 == "position" &&
            (words.size() == 2 || words.size() == 3)) {
            std::string word1 = words.front(); // should be in the form of (x,
            word1 = word1.substr(1);
            word1.pop_back();
            double x = std::stoi(word1);
            std::string word2 = words.front();
            words.erase(words.begin());
            double y = std::stoi(word2);
            Point p(x, y);
            int speed;
            if (!words.empty()) { // its a thug
                std::string word3 = words.back();
                speed = stoi(word3);
            }
            Model::Get().position(name, p, speed);
        }
        if (words.front() == "destination" && words.size() == 1) {
            Model::Get().destination(name, words.back());
        }
        if (words.front() == "stop" && words.empty()) {
            Model::Get().stop(name);
        }
        if (words.front() == "attack" && words.size() == 1) {
            std::string peasant = words.back();
            Model::Get().attack(name, peasant);
        } else {
            throw std::invalid_argument("invalid input");
        }

    }

    catch (const std::exception &e) {
        std::cout << e.what();
    }
    return false;
}

Controller::Controller() {}

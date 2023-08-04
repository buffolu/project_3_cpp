//
// Created by igor on 25/06/2023.
//

#include "Controller.h"

bool Controller::GetUserInput() {
    std::string input;
    if (std::getline(std::cin, input)) {
        if (input == "") {
            model->badInput(input);
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
        if (command == "default" && words.empty()) {
            model->ddefault();

        } else if (command == "size" && words.size() == 1) {
            int s = std::stoi(words.back());
            if (s > 6 && s <= 30) {
                model->setSize(s);
            } else {
                throw std::invalid_argument("invalid input");
            }
        } else if (command == "zoom" && words.size() == 1) {
            int num = std::stoi(words.back());
            if (num > 0) {
                model->zoom(num);
            }

            else {
                throw std::invalid_argument("invalid input");
            }

        }

        else if (command == "pan" && words.size() == 2) {
            words.erase(words.begin());
            double x = stoi(words.front());
            double y = stoi(words.back());
            view.pan(x, y);

        } else if (command == "show" && words.empty()) {
            view.show();
        }

        // line 59- related to model
        else if (command == "status " && words.empty()) {
            model->status();
        } else if (command == "go" && words.empty()) {
            model->go();
        } else if (command == "create" && words.size() == 3 ||
                   words.size() == 4) {
            std::string name = words.front();
            words.erase(words.begin());
            std::string type = words.front(); // knight , thug or peasant
            words.erase(words.begin());
            if (utils::isStringOnlyLetters(name)) {
                throw std::invalid_argument("invalid input");
            }

            if (words.size() == 2 && words.front().size() == 3 &&
                words.back().size() == 2) // coordination in the form of (x,
                                          // y)-thug or peasant or knight.
            {
                std::string word1 =
                    words.front(); // should be in the form of (x,
                word1.substr(1);
                word1.pop_back();
                double x = std::stoi(word1);
                std::string word2 = words.back();
                word2.pop_back();
                double y = std::stoi(word2);
                Point p(x, y);

                model->addAgent(name, type, p);
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
            model->course(name, theta, speed);
        }
        if (command2 == "position" &&
            (words.size() == 2 || words.size() == 3)) {
            std::string word1 = words.front(); // should be in the form of (x,
            word1.substr(1);
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
            model->position(name, p,  speed);
        }
        if (words.front() == "destination" && words.size() == 1) {
            model->destination(name, words.back());
        }
        if (words.front() == "stop" && words.empty()) {
            model->stop(name);
        }
        if (words.front() == "attack" && words.size() == 1) {
            std::string peasant = words.back();
            model->attack(name, peasant);
        } else {
            throw std::invalid_argument("invalid input");
        }

    }

    catch (const std::exception &e) {
        std::cout << e.what();
    }
}

Controller &Controller::Get() {
    static Controller instance;
    return instance;
}


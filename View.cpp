//
// Created by igor on 14/06/2023.
//

#include "View.h"
#include <iostream>

// void View::update_location() {
//
// }

void View::Log(const std::string &str) noexcept {
    std::cout << str << std::endl;
}

std::pair<int, int> View::getSize() {
    return std::pair<int, int>();
}

void View::setSize(int size) {

}

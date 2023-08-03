#include "utils.h"
#include <chrono>
#include <iostream>
#include <sstream>

std::vector<std::string> utils::split(const std::string &str, char delim) {
    std::stringstream ss(str);
    std::vector<std::string> res;
    std::string token;
    while (std::getline(ss, token, delim)) {
        res.push_back(token);
    }
    return res;
}

bool utils::isStringOnlyLetters(const std::string &str) noexcept {
    for (char ch : str) {
        if (!std::isalpha(ch)) {
            return false;
        }
    }
    return true;
}

#pragma once

#include <string>
#include <vector>

class utils {
public: // static methods
    static std::vector<std::string> split(const std::string &str, char delim);
    static bool isStringOnlyLetters(const std::string &str) noexcept;
};

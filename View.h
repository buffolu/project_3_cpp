//
// Created by igor on 14/06/2023.
//

#ifndef PROJECT_3_VIEW_H
#define PROJECT_3_VIEW_H

#include "Model.h"
class View {
    int scale;  // number of kilometers in square side
    int size_x; // size of terminal window
    int size_y;
    Point origin;

public:
    // getters setters
    std::pair<int, int> getSize();
    void setSize(int size);

    // void update_location();

    // void draw();

    // void draw_board(
    inline void Log(const std::string &str) noexcept;
};

#endif // PROJECT_3_VIEW_H

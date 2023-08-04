//
// Created by igor on 14/06/2023.
//

#ifndef PROJECT_3_VIEW_H
#define PROJECT_3_VIEW_H
#include "Geometry.h"
#include <algorithm>
#include <cmath>
#include <memory>
#include <vector>
#include <iostream>


class View {
    std::shared_ptr<std::vector<std::shared_ptr<Sim_object>>> _objects;
    double _scale; // number of kilometers in square side
    int _size;
    Point _pan;
    std::vector<std::vector<char>> _matrix;
    Point _origin;
    void insert(double x, double y, std::shared_ptr<Sim_object> obj);

public:
    // getters setters
    void setPan(double x, double y);
    void makeDefault();
    int getSize();
    void setSize(int size);
    void setScale(double scale);
    void show();
    void addObjects(
        std::shared_ptr<std::vector<std::shared_ptr<Sim_object>>> objects);

    inline void Log(const std::string &str) noexcept;

    View();
};

#endif // PROJECT_3_VIEW_H

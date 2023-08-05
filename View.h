//
// Created by igor on 14/06/2023.
//

#ifndef PROJECT_3_VIEW_H
#define PROJECT_3_VIEW_H

#include "Sim_object.h"
#include "Geometry.h"
#include <vector>
#include <iostream>
#include <memory>
#include <algorithm>


class View {
    std::shared_ptr<std::vector<std::shared_ptr<Sim_object>>> _objects;
    double _scale; // number of kilometers in square side
    int _size;
    Point _pan;
    std::vector<std::vector<std::array<char,2>>> _matrix;

public:
    // getters setters
    void insert(double x, double y, const std::string & name);

    void setPan(double x, double y);
    void makeDefault();
    int getSize() const;
    void setSize(int size);
    void setScale(double scale);
    void show();
    void addObjects(
        std::shared_ptr<std::vector<std::shared_ptr<Sim_object>>>& objects);

    static void Log(const std::string &str);

    View();
};

#endif // PROJECT_3_VIEW_H

//
// Created by igor on 14/06/2023.
//

#include "View.h"

void View::setScale(double scale) { _scale = scale; }
void View::makeDefault() {
    _size = 25;
    _pan = {0, 0};
    _scale = 2;
    setSize(_size);
}

void View::show() {

    // firstly , update matrix.
    for (auto i : _matrix) {
        std::fill(i.begin(), i.end(), '.');
    }
    for (const auto &obj : *_objects) {
        double x = obj->getLocation().x;
        double y = obj->getLocation().y;

        insert(x, y, obj);
    }
    // PRINT
    for (const auto &row : _matrix) {
        for (const auto &sqaure : row) {
            std::cout << sqaure << " ";
        }
        std::cout << "\n";
    }
}

void View::setSize(int size) {
    if (size < 6 || size > 30)
        throw std::exception();

    _matrix.resize(size);
    for_each(_matrix.begin(), _matrix.end(),
             [size](std::vector<char> &object) { object.resize(size); });

    _size = size;
}

int View::getSize() { return _size; }

void View::insert(double x, double y, std::shared_ptr<Sim_object> obj) {
    double range = _size * _scale * 10;

    double x_range = _pan.x + range;
    double y_range = _pan.y = range;

    if (x > x_range || y > y_range || x < _pan.x || y < _pan.y)
        return; // out of range depending on this scale,pan and size.

    int x_cordinate = x / _scale * 10;
    int y_cordinate = y / _scale * 10;

    _matrix.at(x_cordinate).at(y_cordinate) = obj->getName().at(0);
}

void View::setPan(double x, double y) {
    _pan.x = x;
    _pan.y = y;
}

View::View() { makeDefault(); }
void View::addObjects(
    std::shared_ptr<std::vector<std::shared_ptr<Sim_object>>> objects) {
    _objects = objects;
}

void View::Log(const std::string &str) { std::cout << str << std::endl; }

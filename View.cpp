//
// Created by igor on 14/06/2023.
//

#include "View.h"

void View::setScale(double scale) {
    if (scale > 0)
        _scale = scale;
    else 
        Log("scale must be positive");
}

void View::makeDefault() {
    _size = 25;
    _pan = {0, 0};
    _scale = 2;
    setSize(_size);
}

void View::show() {

    // firstly , update matrix.
    for (auto &i : _matrix) {
        i = ". ";
    }
    for (const auto &obj : *_objects) {
        double x = obj->getLocation().x;
        double y = obj->getLocation().y;

        insert(x, y, obj->getName());
    }

    // PRINT
    int scale = (_size * _scale) - _scale;
    int jump = 2;
    if (scale < 25) {
        jump = 0;
    } else if (scale < 50) {
        jump = 1;
    }
    std::cout << "Display size: " << _size << ", scale: " << _scale
              << " origin: (" << _pan.x << ", " << _pan.y << ")\n";

    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            std::cout << _matrix[_size * i + j].substr(0, 2);
        }
        std::cout << std::endl;
    }

    /*
    std::for_each(_matrix.rbegin(), _matrix.rend(),
                  [&jump, &scale](std::vector<std::array<char, 2>> &row) {
                      int runner = 0;
                      for (const auto &sqaure : row) {
                          std::cout << sqaure.front() << sqaure.back();
                      }
                      std::cout << "\n";
                  });
    */
}

void View::setSize(int size) {
    if (size < 6) {
        Log("new size too small");
        return;
    } else if (size >= 30) {
        Log("new size too big");
        return;
    }

    _matrix.resize(size * size);
    _size = size;
    /*
    for_each(_matrix.begin(), _matrix.end(),
             [size](std::vector<std::array<char, 2>> &object) {
                 object.resize(size);
             });
             */
}

int View::getSize() { return _size; }

void View::insert(double x, double y, const std::string &name) {
    double range = _size * _scale;

    double x_range = _pan.x + range;
    double y_range = _pan.y + range;
    // Point top_right{x_range, y_range};

    if (x > x_range || y > y_range || x < _pan.x || y < _pan.y)
        return; // out of range depending on this scale,pan and size.

    int x_cordinate = (x - _pan.x) / _scale;
    int y_cordinate = (y - _pan.y) / _scale;

    _matrix[_size * (_size - y_cordinate - 1) + x_cordinate] = name;
}

void View::setPan(double x, double y) {
    _pan.x = x;
    _pan.y = y;
}

View::View() { makeDefault(); }
void View::addObjects(
    std::shared_ptr<std::vector<std::shared_ptr<Sim_object>>> &objects) {
    _objects = objects;
}

void View::Log(const std::string &str) { std::cout << str << std::endl; }

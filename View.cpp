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
    for ( auto& i : _matrix) {
        std::for_each(i.begin(),i.end(),[](std::array<char,2>& ar){ar[0] = '.'; ar[1] =' ';});
    }
    for (const auto &obj : *_objects) {
        double x = obj->getLocation().x;
        double y = obj->getLocation().y;

        insert(x, y, obj->getName());
    }
    // PRINT
    int scale = (_size * _scale)-_scale;
    int jump = 2;
    if(scale<25)
    {
        jump = 0;
    }
    if(scale>25 && scale<50)
    {
        jump = 1;
    }

    std::for_each(_matrix.rbegin(),_matrix.rend(),[&jump,&scale](std::vector<std::array<char,2> >& row) {
        int runner = 0;
        for (const auto &sqaure: row) {
            if(jump == 0)
            std::cout << sqaure.front()<<sqaure.back();
        }
        std::cout << "\n";
    });
}

void View::setSize(int size) {
    if (size < 6 || size > 30)
        throw std::exception();

    _matrix.resize(size);
    for_each(_matrix.begin(), _matrix.end(),
             [size](std::vector<std::array<char,2>> &object) { object.resize(size); });

    _size = size;
}

int View::getSize() { return _size; }

void View::insert(double x, double y, const std::string& name) {
    double range = _size * _scale ;

    double x_range = _pan.x + range;
    double y_range = _pan.y + range;

    if (x > x_range || y > y_range || x < _pan.x || y < _pan.y)
        return; // out of range depending on this scale,pan and size.

    int x_cordinate =  x / (_scale-_pan.x );
    int y_cordinate = y / (_scale-_pan.y );

\


    _matrix.at(y_cordinate).at(x_cordinate).front() = name[0];
    _matrix.at(y_cordinate).at(x_cordinate).back() = name[1];

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

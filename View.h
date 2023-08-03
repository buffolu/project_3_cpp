//
// Created by igor on 14/06/2023.
//

#ifndef PROJECT_3_VIEW_H
#define PROJECT_3_VIEW_H
#include <memory>
#include <list>
#include <cmath>
#include "Geometry.h"
template<typename objType>
class View {
    double _scale;  // number of kilometers in square side
    int _size;
    Point _pan;
    vector<vector<char>> _matrix;
    Point _origin;
    void insert(double x , double y,const shared_ptr<objType>& obj);
public:

    // getters setters
    int getSize();
    void setSize(int size);
    void setScale(double scale);
    void show(std::shared_ptr<list<shared_ptr<objType>>> objects);


    inline void Log(const std::string &str) noexcept;
};

template<typename objType>
void View<objType>::setScale(double scale) {
    scale = scale;
}

template<typename objType>
void View<objType>::show(shared_ptr<list<shared_ptr<objType>>> objects) {
    //firstly , update matrix.
    for(auto i : _matrix) { std::fill(i.begin(), i.end(),".");}
    for(const auto& obj : *objects)
    {
        double x = obj->getLocation().x;
        double y = obj->getLocation().y;

        insert(x,y,*obj);
    }




}

template<typename objType>
void View<objType>::setSize(int size) {
    _size = size;
}

template<typename objType>
int View<objType>::getSize() {
    return _size;
}

template<typename objType>
void View<objType>::insert(double x, double y,const shared_ptr<objType>& obj ) {
    double range = _size * _scale * 10;

    double x_range = _pan.x + range;
    double y_range = _pan.y = range;


    if (x > x_range || y > y_range || x < _pan.x || y < _pan.y) return;

    int x_cordinate = x / _scale * 10;
    int y_cordinate = y / _scale * 10;

    _matrix.at(x_cordinate).at(y_cordinate) = obj->getName().at(0);
}

#endif // PROJECT_3_VIEW_H

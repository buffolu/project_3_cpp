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
    View();
    // getters setters
    void setPan(double x,double y);
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

    for(const auto& row: _matrix)
    {
        for(const auto& sqaure: row)
        {
            std::cout<<sqaure<<" ";
        }
        std::cout<<"\n";
    }
}

template<typename objType>
void View<objType>::setSize(int size) {
    if(size<6 || size > 30) throw exception();


    _matrix.resize(size);
    for_each(_matrix.begin(),_matrix.end(),[size](std::vector<objType>& object)
    {
        object.resize(size);
    });

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


    if (x > x_range || y > y_range || x < _pan.x || y < _pan.y) return; //out of range depending on this scale,pan and size.

    int x_cordinate = x / _scale * 10;
    int y_cordinate = y / _scale * 10;

    _matrix.at(x_cordinate).at(y_cordinate) = obj->getName().at(0);
}

template<typename objType>
void View<objType>::setPan(double x, double y) {
    _pan.x = x; _pan.y = y;}

template<typename objType>
View<objType>::View() {
    _size  = 25;
    _pan = {0,0};
    _scale = 2;
}


#endif // PROJECT_3_VIEW_H

//
// Created by igor on 04/08/2023.
//
#include "Farm.h"

#include <utility>

Farm::Farm(const std::string &name, Point p, int hay, int produceRate)
    : Structure(name, p, hay), _produceRate(produceRate) {}

void Farm::update() { addToHay(_produceRate); }

int Farm::takeCrates(int amount) {
    int returnAmount = amount;
    if (getHay() <= amount) {
        returnAmount = getHay();
        setHay(0);
    } else {
        addToHay(-amount);
    }
    return returnAmount;
}

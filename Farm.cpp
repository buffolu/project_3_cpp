//
// Created by igor on 04/08/2023.
//
#include "Farm.h"

#include <utility>



Farm::Farm(string name, Point p, int hay, int produceRate) : Structure(std::move(name), p, hay,FARM),_produceRate(produceRate) {

}

void Farm::update() {
    addToHay(_produceRate);

}

int Farm::takeCrates(int amount) {
    int returnAmount = amount;
    if(getHay() <=amount)
    {
        returnAmount = getHay();
        setHay(0);
    }
    else
    {
        addToHay(-amount);
    }
    return returnAmount;
}

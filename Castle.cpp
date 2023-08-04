//
// Created by igor on 04/08/2023.
//
#include "Castle.h"

#include <utility>

void Castle::giveCrates(int crates) { addToHay(crates); }

Castle::Castle(const std::string &name, Point position, int hay)
    : Structure(std::move(name), position, hay) {}

void Castle::update() {}

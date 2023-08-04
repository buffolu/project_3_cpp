#pragma once

#include "Structure.h"

class Farm : public Structure {
    int _produceRate;

public:
    Farm(const std::string &name, Point p, int hay, int produceRate);
    void update() override;
    int takeCrates(int amount = 5);
};

#pragma once

#include <cmath>
#include "EZ-Template/api.hpp"
#include "robot.hpp"


class Autons {
public:
    static void tuneDrive();
    static void tuneTurn();
    static void doNothing();
    static void skills();
    static void offensive();
    static void defensiveQual();
    static void defensiveElims();
};

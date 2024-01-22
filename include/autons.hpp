#pragma once

#include "EZ-Template/api.hpp"
#include "robot.hpp"


class Autons {
public:
    static void doNothing();
    static void skills();
    static void offensive();
    static void defensiveQual();
    static void defensiveElims();

    static void addAutons(AutonSelector autonSelector);
};

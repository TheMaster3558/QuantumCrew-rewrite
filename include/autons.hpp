#pragma once

#include "EZ-Template/api.hpp"
#include "robot.hpp"


class Autons {
public:
    static void doNothing();
    static void skills();
    static void defensiveQual();
    static void defensiveElims();
    static void offensiveQual();
    static void offensiveElims();

    static void addAutons(AutonSelector autonSelector);
};

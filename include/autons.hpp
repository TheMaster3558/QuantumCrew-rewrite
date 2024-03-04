#pragma once

#include <cmath>
#include "EZ-Template/api.hpp"
#include "robot.hpp"


#define ODOM_UPDATE_DELAY 10
#define Tiles(x) (24 * x)


namespace Autons {

void tuneDrive();
void tuneTurn();
void doNothing();
void skills();
void sixBall();
void nearSideSafeAWP();
void nearSideAggressiveAWP();
void nearSideDisruptAWP();

namespace utils {
    void moveRelative(double distance, int timeout, bool forwards = false);
    void waitUntilBelowBar();
}

}  // namespace Autons


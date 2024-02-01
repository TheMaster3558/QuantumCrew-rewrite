#include "autons.hpp"


void Autons::tuneDrive() {
    Robot::chassis.moveToPose(0, 10, 0, 30000);
    Robot::chassis.waitUntilDone();
}


void Autons::tuneTurn() {
    Robot::chassis.turnTo(30, 0, 2000);
    Robot::chassis.waitUntilDone();
}

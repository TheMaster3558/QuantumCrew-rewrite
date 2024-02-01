#include "autons.hpp"


void Autons::tuneDrive() {
    chassis.moveToPose(0, 10, 0, 30000);
    chassis.waitUntilDone();
}


void Autons::tuneTurn() {
    chassis.turnTo(30, 0, 2000);
    chassis.waitUntilDone();
}

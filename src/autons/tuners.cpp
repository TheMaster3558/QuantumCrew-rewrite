#include "autons.hpp"


void Autons::tuneDrive() {
    chassis.moveToPoint(0, 10, 3000);
    chassis.waitUntilDone();
}


void Autons::tuneTurn() {
    chassis.turnTo(30, 0, 2000);
    chassis.waitUntilDone();
}

#include "autons.hpp"


void Autons::Autons::offensive() {
    chassis.setPose(33, -58, 0);

    chassis.moveToPoint(33, -10, 3000);
    chassis.waitUntilDone();

    chassis.turnTo(50, -10, 1000);
    chassis.waitUntilDone();

    Actions::Intake::outtake();
    pros::delay(2000);
    Actions::Intake::brake();

    chassis.moveToPoint(25, -10, 3000);
    chassis.waitUntilDone();

    chassis.turnTo(50, -10, 1000, false);
    chassis.waitUntilDone();

    chassis.moveToPose(50, -10, 270, 4000, {
        .forwards = false,
        .minSpeed = 110
    });
    chassis.waitUntilDone();
}

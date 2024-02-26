#include "autons.hpp"


ASSET(skills_move_across_field_txt)
ASSET(skills_move_to_front)


void Autons::Autons::skills() {
    chassis.setPose(-45, -56, 135);

    moveRelative(-10, 1500, false);
    chassis.waitUntilDone();

    chassis.turnTo(70, -8, 2000, false);
    chassis.waitUntilDone();

    Actions::Wings::setFront(true, false);

    Actions::Catapult::lower();
    pros::delay(30000);
    Actions::Catapult::brake();

    Actions::Wings::setFront(false, false);

    chassis.setPose(-55, -44, 255);

    pros::delay(500);

    chassis.turnTo(-55, 0, 2000, false);
    chassis.waitUntilDone();

    chassis.tank(-127, -127);
    pros::delay(1000);
    chassis.tank(0, 0);
    pros::delay(200);

    chassis.setPose(-60, -33, 180);

    chassis.follow(skills_move_across_field_txt, 13, 4000);
    chassis.waitUntil(110);
    Actions::Wings::setFront(true, true);
    chassis.waitUntilDone();


    chassis.tank(-75, -75);
    pros::delay(300);

    Actions::Wings::setFront(false, false);

    chassis.moveToPoint(60, -20, 1000, false);
    chassis.waitUntilDone();

    chassis.setPose(60, -32, chassis.getPose().theta);

    chassis.follow(skills_move_to_front, 10, 4000);
    chassis.waitUntilDone();

    chassis.moveToPose(60, -7, 90, 3000, {
        .lead = 0.7,
        .minSpeed = 110,
    });
    chassis.waitUntil(7);
    Actions::Wings::setFront(true, true);
    chassis.waitUntilDone();

    chassis.setPose(45, -10, chassis.getPose().theta);

    Actions::Wings::setFront(false, false);

    chassis.moveToPose(14, 15, 0, 3000, {
        .lead = 1.0
    });
    chassis.waitUntilDone();

    Actions::Wings::setRear(true, true);

    chassis.moveToPose(60, 6, 270, 4000, {
        .forwards = false,
        .lead = 0.8,
        .minSpeed = 110
    });
    chassis.waitUntilDone();

    chassis.setPose(45, 10, chassis.getPose().theta);

    Actions::Wings::setRear(false, false);
}

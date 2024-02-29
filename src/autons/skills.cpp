#include "autons.hpp"


ASSET(skills_move_across_field_txt)


void Autons::skills() {
    chassis.setPose(-45, -56, 135);

    Autons::utils::moveRelative(-10, 1500, false);
    chassis.waitUntilDone();

    chassis.turnTo(60, -8, 2000, false);
    chassis.waitUntilDone();

    Actions::Wings::setFront(true, false);

    Actions::Catapult::lower();
    pros::delay(30000);
    Actions::Catapult::brake();

    Actions::Wings::setFront(false, false);

    chassis.setPose(-55, -44, 255);

    pros::delay(500);

    chassis.moveToPoint(-55, 0, 2000, false);
    chassis.waitUntilDone();

    chassis.setPose(-60, -33, 180);

    chassis.follow(skills_move_across_field_txt, 13, 4000);
    chassis.waitUntil(110);
    Actions::Wings::setFront(true, true);
    chassis.waitUntilDone();

    chassis.moveToPoint(60, chassis.getPose().y - 5, 1000, false);
    chassis.waitUntilDone();

    Actions::Wings::setFront(false, false);

    chassis.moveToPoint(60, -20, 1000);
    chassis.waitUntilDone();

    chassis.setPose(60, -30, chassis.getPose().theta);

    chassis.moveToPoint(60, -35, 1000);
    chassis.waitUntilDone();

    chassis.moveToPoint(14, -32, 3000);
    chassis.waitUntilDone();

    chassis.moveToPose(60, -7, 90, 3000, {
        .lead = 0.7,
        .minSpeed = 110
    });
    chassis.waitUntil(7);
    Actions::Wings::setFront(true, true);
    chassis.waitUntilDone();

    chassis.setPose(45, -10, chassis.getPose().theta);

    Actions::Wings::setFront(false, false);

    chassis.moveToPoint(14, -10, 1000, false);
    chassis.waitUntilDone();

    chassis.moveToPoint(14, 32, 1000, false);
    chassis.waitUntilDone();

    Actions::Wings::setRear(true, true);

    chassis.turnTo(10000, chassis.getPose().y, 1000);
    chassis.waitUntilDone();

    chassis.moveToPose(60, 5, 270, 2000, {
        .forwards = false,
        .lead = 0.7,
        .minSpeed = 110
    });
    chassis.waitUntilDone();

    chassis.setPose(42, 6, chassis.getPose().theta);

    chassis.moveToPose(33, 58, 0, 2000, {
        .lead = 1.0
    });
    chassis.waitUntilDone();

    chassis.moveToPose(60, 0, 180, 3000);
    chassis.waitUntil(10);
    Actions::Wings::setFront(true, true);
    chassis.waitUntilDone();

    chassis.moveToPoint(60, chassis.getPose().y + 5, 1000, false);
    chassis.waitUntilDone();

    Actions::Wings::setFront(false, false);

    chassis.moveToPoint(60, 20, 1000);
    chassis.waitUntilDone();

    chassis.setPose(60, 30, chassis.getPose().theta);

    chassis.moveToPoint(60, 35, 1000);
    chassis.waitUntilDone();
}

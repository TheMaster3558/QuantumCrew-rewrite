#include "autons.hpp"


ASSET(skills_move_across_field_txt)
ASSET(skills_move_across_top_field_txt)


void Autons::skills() {
    chassis.setPose(-47, -55, 135);

    chassis.moveToPose(-61, -10, 180, 1000, {
        .forwards = false,
        .minSpeed = 110
    });
    chassis.waitUntilDone();

    chassis.setPose(-60, -32, chassis.getPose().theta);

    chassis.moveToPoint(-60, -42, 1000);
    chassis.waitUntilDone();

    chassis.turnTo(35, -10, 1000);
    chassis.waitUntilDone();

    Actions::Wings::setRear(false, true);

    lemlib::Pose beforeMatchLoad = chassis.getPose();
    Actions::Catapult::lower();
    pros::delay(25000);
    Actions::Catapult::brake();
    chassis.setPose(beforeMatchLoad);

    Actions::Wings::setRear(false, false);

    chassis.follow(skills_move_across_field_txt, 13, 3500);
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

    chassis.tank(-50, -50);
    pros::delay(500);
    chassis.tank(100, 100);
    pros::delay(1000);
    chassis.tank(0, 0);

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

    chassis.tank(50, 50);
    pros::delay(500);
    chassis.tank(-100, -100);
    pros::delay(1000);
    chassis.tank(0, 0);

    chassis.setPose(38, 6, chassis.getPose().theta);

    chassis.moveToPoint(34, 6, 1000);
    chassis.waitUntilDone();

    Actions::Wings::setRear(false, false);

    chassis.moveToPose(33, 58, 0, 2000);
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

void skills() {
    chassis.setPose(-47, -55, 135);

    chassis.moveToPose(-61, -10, 180, 1000, {
            .forwards = false,
            .minSpeed = 110
    });
    chassis.waitUntilDone();

    chassis.setPose(-60, -32, chassis.getPose().theta);

    chassis.moveToPoint(-60, -42, 1000);
    chassis.waitUntilDone();

    chassis.turnTo(35, -10, 1000);
    chassis.waitUntilDone();

    Actions::Wings::setRear(false, true);

    lemlib::Pose beforeMatchLoad = chassis.getPose();
    Actions::Catapult::lower();
    pros::delay(25000);
    Actions::Catapult::brake();
    chassis.setPose(beforeMatchLoad);

    Actions::Wings::setRear(false, false);

    chassis.moveToPoint(-12, -35, 1000);
    chassis.waitUntilDone();

    Actions::Wings::setFront(true, true);

    chassis.moveToPoint(-12, 38, 2000);
    chassis.waitUntilDone();

    Actions::Wings::setFront(false, false);

    chassis.moveToPose(-47, 51, 0, 2000);
    chassis.waitUntilDone();

    chassis.follow(skills_move_across_top_field_txt, 13, 3500);
    chassis.waitUntil(90);
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

    chassis.moveToPoint(14, 32, 3000);
    chassis.waitUntilDone();

    chassis.moveToPose(60, 7, 90, 3000, {
            .lead = 0.7,
            .minSpeed = 110
    });
    chassis.waitUntil(7);
    Actions::Wings::setFront(true, true);
    chassis.waitUntilDone();

    chassis.tank(-50, -50);
    pros::delay(500);
    chassis.tank(100, 100);
    pros::delay(1000);
    chassis.tank(0, 0);

    chassis.setPose(45, 10, chassis.getPose().theta);

    Actions::Wings::setFront(false, false);

    chassis.moveToPoint(14, 10, 1000, false);
    chassis.waitUntilDone();

    chassis.moveToPoint(14, -32, 1000, false);
    chassis.waitUntilDone();

    Actions::Wings::setRear(true, true);

    chassis.turnTo(10000, chassis.getPose().y, 1000);
    chassis.waitUntilDone();

    chassis.moveToPose(60, -5, 270, 2000, {
            .forwards = false,
            .lead = 0.7,
            .minSpeed = 110
    });
    chassis.waitUntilDone();

    chassis.tank(50, 50);
    pros::delay(500);
    chassis.tank(-100, -100);
    pros::delay(1000);
    chassis.tank(0, 0);

    chassis.setPose(38, -6, chassis.getPose().theta);

    chassis.moveToPoint(34, -6, 1000);
    chassis.waitUntilDone();

    Actions::Wings::setRear(false, false);

    chassis.moveToPose(33, -58, 180, 2000);
    chassis.waitUntilDone();

    chassis.moveToPose(60, 0, 0, 3000);
    chassis.waitUntil(10);
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
}

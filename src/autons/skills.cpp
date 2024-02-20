#include "autons.hpp"


ASSET(skills_prepare_for_first_ram_txt)
ASSET(skills_move_across_field_txt)


void Autons::Autons::skills() {
    /*
    chassis.setPose(-47, -60, 220);

    Actions::Wings::setFront(false, true);

    Actions::Catapult::lower();
    pros::delay(500);
    Actions::Wings::setFront(false, false);
    pros::delay(40000);
    Actions::Catapult::brake();

    chassis.moveToPose(-68, -27, 180, 2000, {
            .forwards = false,
            .minSpeed = 110,
    });
    chassis.waitUntilDone();

    chassis.setPose(-68, -32, chassis.getPose().thetha);

    chassis.moveToPose(-30, -57, 90, 3000);
    chassis.waitUntil(40);
    chassis.cancelMotion();

    chassis.moveToPoint(40, -57, 3000);
    chassis.waitUntil(70);
    chassis.cancelMotion();

    chassis.moveToPoint(65, -10, 2000);
    chassis.waitUntil(5);
    Actions::Wings::setFront(false, true);
    chassis.waitUntil(16);
    chassis.cancelMotion();

    chassis.turnTo(55, 0, 1000);
    chassis.waitUntilDone();

    Actions::Wings::setFront(true, true);

    chassis.tank(100, 127);
    pros::delay(1000);
    Actions::Wings::setFront(false, false);
    chassis.tank(-75, -75);
    pros::delay(500);
    chassis.tank(127, 127);
    pros::delay(1000);

    chassis.setPose(62, -28, chassis.getPose().theta);

    chassis.follow(skills_prepare_for_first_ram_txt, 10, 4000, false);
    chassis.waitUntil(60);
    chassis.cancelMotion();

    Actions::Wings::setRear(true, true);

    chassis.moveToPose(60, -8, 270, 1000, {
        .forwards = false,
        .minSpeed = 110
    });
    chassis.waitUntilDone();

    chassis.setPose(45, 8, chassis.getPose().theta);
     */

    chassis.setPose(-60, 32, 180);

    chassis.follow(skills_move_across_field_txt, 13, 4000);
    chassis.waitUntilDone();

    chassis.turnTo(58, -42, 1000);
    chassis.waitUntilDone();

    Actions::Wings::setFront(true, true);

    chassis.moveToPose(60, -32, 0, 2000, {
        .minSpeed = 110
    });
    chassis.waitUntilDone();

    chassis.tank(-75, -75);
    pros::delay(500);

    Actions::Wings::setFront(false, false);

    chassis.tank(127, 127);
    pros::delay(100);

    chassis.setPose(60, -32, chassis.getPose().theta);

    chassis.moveToPoint(60, -37, 1000, false);
    chassis.waitUntilDone();

    chassis.moveToPoint(10, -25, 1500);
    chassis.waitUntilDone();

    chassis.turnTo(42, -10, 1000);
    chassis.waitUntilDone();
}

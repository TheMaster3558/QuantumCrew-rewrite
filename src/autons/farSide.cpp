#include "autons.hpp"


ASSET(far_side_match_load_txt)


void Autons::sixBall() {
    /*
    chassis.setPose(5, Tiles(-2.5), 270);

    chassis.moveToPoint(2, Tiles(-2.5), 1000);
    Actions::Intake::intake();
    chassis.waitUntilDone();
    Actions::Intake::brake();

    chassis.moveToPoint(30, Tiles(-2.5), 1000, false);
    chassis.waitUntilDone();

    pros::delay(500);

    chassis.moveToPoint(53, -43, 1000, false);
    chassis.waitUntil(2);
    Actions::Wings::setRear(true, false);
    chassis.waitUntil(6);
    Actions::Wings::setRear(false, false);
    chassis.waitUntilDone();

    pros::delay(1000);

    chassis.moveToPoint(58, -20, 1000, false);
    chassis.waitUntilDone();

    chassis.setPose(58, -33, 180);

    chassis.moveToPoint(58, -40, 2000);
    chassis.waitUntilDone();

    chassis.moveToPoint(58, -20, 2000);
    chassis.waitUntil(6);
    Actions::Intake::outtake();
    chassis.waitUntilDone();
    Actions::Intake::brake();

    chassis.setPose(60, -32, chassis.getPose().theta);

    chassis.moveToPoint(60, -50, 5000, false);
    chassis.waitUntilDone();

    chassis.moveToPoint(8, -25, 3000);
    Actions::Intake::intake();
    chassis.waitUntilDone();
    Actions::Intake::brake();

    chassis.turnTo(60, -20, 1000);
    chassis.waitUntilDone();

    Actions::Intake::outtake();
    pros::delay(750);
    Actions::Intake::brake();

    chassis.turnTo(-10, -6, 1000);
    chassis.waitUntilDone();

    chassis.moveToPoint(-10, -6, 2000, 80);
    Actions::Intake::intake();
    chassis.waitUntilDone();
    Actions::Intake::brake();

    chassis.moveToPose(60, -15, 270, 2000, {
        .minSpeed = 110,
    });
    chassis.waitUntil(5);
    Actions::Intake::outtake();
    Actions::Wings::setFront(true, true);
    chassis.waitUntilDone();
    Actions::Intake::brake();

    Actions::Wings::setFront(false, false);
     */
    chassis.tank(-127, -127);
    pros::delay(6000);
    chassis.tank(0, 0);
}
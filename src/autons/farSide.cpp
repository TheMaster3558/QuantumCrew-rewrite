#include "autons.hpp"


ASSET(far_side_match_load_txt)


void Autons::sixBall() {
    chassis.setPose(5, Tiles(-2.5), 270);

    chassis.moveToPoint(2, Tiles(-2.5), 1000);
    Actions::Intake::intake();
    chassis.waitUntilDone();
    Actions::Intake::brake();

    chassis.moveToPoint(40, Tiles(-2.5), 1000, false);
    chassis.waitUntilDone();

    chassis.moveToPoint(58, -43, 1000, false);
    chassis.waitUntil(2);
    Actions::Wings::setRear(true, false);
    chassis.waitUntil(6);
    Actions::Wings::setRear(false, false);
    chassis.waitUntilDone();

    pros::delay(1000);

    chassis.moveToPoint(58, 20, 1000, false);
    chassis.waitUntilDone();

    chassis.setPose(58, 33, chassis.getPose().theta);

    chassis.moveToPoint(58, 30, 1000);
    chassis.waitUntilDone();
}
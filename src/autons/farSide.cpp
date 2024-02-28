#include "autons.hpp"


ASSET(far_side_match_load_txt)


void Autons::sixBall() {
    chassis.setPose(Tiles(1.5), Tiles(-2.5), 340);
    lemlib::Pose start = chassis.getPose();

    chassis.moveToPoint(25, -5, 2000);
    chassis.waitUntil(15);
    Actions::Intake::intake();
    chassis.waitUntilDone();
    Actions::Intake::brake();

    chassis.moveToPose(start.x, start.y, start.theta, 2000, {
        .forwards = false
    });
    chassis.waitUntilDone();

    chassis.turnTo(57, -38, 1000);
    chassis.waitUntilDone();

    Actions::Intake::outtake();
    pros::delay(500);
    Actions::Intake::brake();

    chassis.moveToPoint(3, -58, 2000);
    chassis.waitUntil(10);
    Actions::Intake::intake();
    chassis.waitUntilDone();
    Actions::Intake::brake();

    chassis.moveToPoint(46, -58, 1000, false);
    chassis.waitUntilDone();

    Actions::Wings::setRear(true, false);
    chassis.moveToPoint(56, -48, 1000, false);
    chassis.waitUntilDone();
    Actions::Wings::setRear(false, false);

    pros::delay(250);

    chassis.moveToPoint(60, 0, 1000, false);
    chassis.waitUntilDone();

    chassis.setPose(60, -32, chassis.getPose().theta);

    chassis.moveToPoint(60, -35, 1000);
    chassis.waitUntilDone();

    chassis.moveToPoint(60, 0, 500);
    chassis.waitUntilDone();

    chassis.setPose(60, -30, chassis.getPose().theta);
}
#include "autons.hpp"


ASSET(offensive_center_to_border_ball_txt)


void Autons::Autons::offensive() {
    int startX = -43;
    int startY = 57;

    int firstTriballX = -9;
    int firstTriballY = 5;
    chassis.setPose(startX, startY, M_PI_2, std::abs(std::atan((double)(startY - firstTriballY) / (startX - firstTriballX))), true);
    //                                      force into q1

    Actions::Wings::setFront(false, true);
    pros::delay(200);
    Actions::Wings::setFront(false, false);

    chassis.moveToPoint(firstTriballX, firstTriballY, 2000);
    Actions::Intake::intake();
    chassis.waitUntilDone();
    Actions::Intake::brake();

    chassis.turnTo(-45, 5, 2000);
    chassis.waitUntil(80);
    chassis.cancelMotion();

    Actions::Wings::setFront(true, true);
    chassis.moveToPose(-40, 5, 270, 2000, {
        .minSpeed = 110
    });

    chassis.setPose(-40, 5, 270);

    chassis.moveToPoint(0, 5, 1000, false);
    chassis.waitUntil(10);
    chassis.cancelMotion();

    Actions::Wings::setFront(false, false);

    chassis.moveToPose(-11, 20, 60, 2000);
    Actions::Intake::intake();
    chassis.waitUntilDone();
    Actions::Intake::brake();

    chassis.follow(offensive_center_to_border_ball_txt, 12, 7000);
    chassis.waitUntil(30);
    Actions::Intake::outtake();
    pros::delay(1000);
    Actions::Intake::brake();

    chassis.waitUntil(50);
    Actions::Intake::intake();
    pros::delay(1000);
    Actions::Intake::brake();

    chassis.moveToPose(-45, 55, 75, 2000, {
        .forwards = false
    });
    chassis.waitUntilDone();

    chassis.turnTo(-60, 50, 100);
    chassis.waitUntilDone();

    Actions::Wings::setFront(true, true);

    chassis.moveToPose(-60, 30, 180, 2000, {
        .minSpeed = 110
    });
    chassis.waitUntilDone();

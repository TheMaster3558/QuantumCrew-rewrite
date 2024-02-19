#include "autons.hpp"


ASSET(offensive_second_half_txt)


void Autons::Autons::offensive() {
    int startX = -43;
    int startY = 59;

    int firstTriballX = -25;
    int firstTriballY = 6;
    chassis.setPose(startX, startY,
                    M_PI_2 + std::abs(std::atan((double) (startY - firstTriballY) / (startX - firstTriballX))), true);
    //                                      force into q1

    Actions::Wings::setFront(false, true);
    pros::delay(200);
    Actions::Wings::setFront(false, false);

    chassis.moveToPoint(firstTriballX, firstTriballY, 2000);
    Actions::Intake::intake();
    chassis.waitUntilDone();
    Actions::Intake::brake();

    chassis.turnToPoint(-30, 10, 1000);
    chassis.waitUntilDone();

    Actions::Intake::outtake();
    pros::delay(500);
    Actions::Intake::brake();

    chassis.moveToPoint(0, -8, 1000);
    Actions::Intake::intake();
    chassis.waitUntilDone();
    Actions::Intake::brake();

    chassis.turnTo(-30, 10, 1000);
    chassis.waitUntilDone();

    chassis.moveToPoint(-7, 18, 1000);
    chassis.waitUntilDone();

    chassis.moveToPose(-60, 10, 270, 3000, {
        .minSpeed = 110
    });
    chassis.waitUntil(20);
    Actions::Wings::setFront(true, true);
    chassis.waitUntilDone();
    Actions::Wings::setFront(false, false);

    chassis.setPose(-42, 0, chassis.getPose().theta);

    chassis.follow(offensive_second_half_txt, 15, 3000, false);
    chassis.waitUntilDone();

    chassis.moveToPoint(-10, 58, 2000);
    Actions::Intake::intake();
    chassis.waitUntilDone();
    Actions::Intake::brake();
}
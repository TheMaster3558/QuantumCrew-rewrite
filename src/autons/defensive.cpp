#include "autons.hpp"


ASSET(defensive_qual_move_to_center_txt);
ASSET(defensive_elims_move_from_goal_to_bar_txt)


void Autons::Autons::defensiveQual() {
    chassis.setPose(47, 57, 315);

    chassis.moveToPose(58, 35, 180, 2000, {
        .forwards = false,
        .minSpeed = 110
    });

    chassis.setPose(58, 35, 180);

    chassis.follow(defensive_qual_move_to_center_txt, 15, 13000);

    chassis.waitUntil(20);
    Actions::Wings::setFront(false, true);
    pros::delay(1500);
    Actions::Wings::setFront(false, false);

    chassis.waitUntil(70);
    Actions::Intake::intake();
    pros::delay(1000);
    Actions::Intake::brake();

    chassis.waitUntil(160);
    Actions::Intake::outtake();
    pros::delay(1000);
    Actions::Intake::brake();
}


void Autons::Autons::defensiveElims() {
    chassis.setPose(35, 60, 180);

    chassis.moveToPoint(35, 10, 3000);
    chassis.waitUntilDone();

    chassis.turnTo(45, 10, 1000);
    chassis.waitUntilDone();

    chassis.moveToPoint(30, 10, 2000);
    chassis.waitUntilDone();

    Actions::Wings::setBack(true);

    chassis.moveToPose(5, 10, 90, 2000, {
        .forwards = false,
        .minSpeed = 110
    });
    chassis.waitUntilDone();

    chassis.moveToPose(45, 10, 270, 2000, {
        .forwards = false,
        .minSpeed = 110
    });
    chassis.waitUntil(5);
    Actions::Wings::setBack(false);
    chassis.waitUntilDone();

    chassis.setPose(45, 10, 270);

    chassis.moveToPose(33, 45, 0, 3000);
    chassis.waitUntilDone();

    chassis.follow(defensive_elims_move_from_goal_to_bar_txt, 13, 7000);
    chassis.waitUntilDone();
}

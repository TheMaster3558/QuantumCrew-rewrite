#include "autons.hpp"


ASSET(defensive_qual_move_to_center_txt)
ASSET(defensive_elims_move_from_goal_to_bar_txt)


void Autons::Autons::defensiveQual() {
    chassis.setPose(42, 57, 135);

    chassis.moveToPoint(54, 47, 1000);
    chassis.waitUntilDone();

    Actions::Wings::setRear(true, false);

    chassis.moveToPoint(42, 57, 1000, false);
    chassis.waitUntilDone();

    chassis.moveToPoint(55, 40, 3000);
    chassis.waitUntil(5);
    Actions::Wings::setRear(false, false);
    chassis.waitUntilDone();

    chassis.turnTo(55, 29, 1000);
    chassis.waitUntilDone();

    Actions::Intake::outtake();
    chassis.waitUntilDone();
    pros::delay(500);
    Actions::Intake::brake();

    chassis.turnTo(55, 28, 1000, false);
    chassis.waitUntilDone();

    chassis.moveToPose(55, 28, 0, 1000, {
            .forwards = false,
            .maxSpeed = 80,
            .minSpeed = 60
    });
    chassis.waitUntilDone();

    chassis.setPose(55, 34, chassis.getPose().theta);

    chassis.moveToPose(3, 58, 270, 7000);
    chassis.waitUntilDone();
}


void Autons::Autons::defensiveElims() {
    chassis.setPose(35, 60, 180);

    chassis.moveToPoint(35, 10, 3000);
    chassis.waitUntilDone();

    chassis.turnTo(45, 10, 1000);
    chassis.waitUntilDone();

    Actions::Intake::outtake();
    pros::delay(1000);
    Actions::Intake::brake();

    chassis.moveToPoint(30, 10, 2000);
    chassis.waitUntilDone();

    chassis.turnTo(5, 10, 1000);
    chassis.waitUntilDone();

    Actions::Wings::setFront(true, true);

    chassis.moveToPose(5, 10, 90, 2000, {
        .minSpeed = 110
    });
    chassis.waitUntilDone();

    Actions::Wings::setFront(false, false);

    chassis.moveToPose(45, 10, 270, 2000, {
        .forwards = false,
        .maxSpeed = 80,
        .minSpeed = 60
    });
    chassis.waitUntil(5);
    Actions::Wings::setRear(true, true);
    chassis.waitUntilDone();

    chassis.setPose(45, 10, chassis.getPose().theta);

    chassis.moveToPose(33, 45, 0, 3000);
    chassis.waitUntilDone();

    Actions::Wings::setRear(false, false);

    chassis.follow(defensive_elims_move_from_goal_to_bar_txt, 13, 7000);
    chassis.waitUntilDone();
}

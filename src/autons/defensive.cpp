#include "autons.hpp"


ASSET(defensive_qual_move_from_goal_to_bar_txt)
ASSET(defensive_elims_move_from_goal_to_bar_txt)


void Autons::Autons::defensiveQual() {
    chassis.setPose(42, 60, 135);

    chassis.moveToPoint(55, 48, 1000);
    chassis.waitUntilDone();

    Actions::Flaps::setFlaps(true, false);

    chassis.moveToPoint(42, 60, 1000, false);
    chassis.waitUntilDone();

    Actions::Flaps::setFlaps(false, false);

    chassis.moveToPose(60, 40, 180, 3000);
    chassis.waitUntil(10);
    Actions::Intake::outtake();
    chassis.waitUntilDone();
    pros::delay(500);
    Actions::Intake::brake();

    chassis.turnTo(60, 28, 1000, false);
    chassis.waitUntilDone();

    chassis.moveToPose(60, 28, 0, 3000, {
        .forwards = false,
        .minSpeed = 110
    });
    chassis.waitUntilDone();

    chassis.follow(defensive_qual_move_from_goal_to_bar_txt, 13, 1000);
    chassis.waitUntilDone();
}


void Autons::Autons::defensiveElims() {
    chassis.setPose(35, 63, 180);

    chassis.moveToPoint(35, 10, 3000);
    chassis.waitUntilDone();

    chassis.turnTo(45, 10, 1000);
    chassis.waitUntilDone();

    Actions::Flaps::setFlaps(true, true);

    chassis.moveToPose(5, 10, 90, 2000, {
        .forwards = false,
        .minSpeed = 110
    });
    chassis.waitUntilDone();

    Actions::Flaps::setFlaps(false, false);

    chassis.moveToPose(45, 10, 90, 2000, {
        .minSpeed = 110
    });
    chassis.waitUntilDone();

    chassis.moveToPoint(35, 10, 2000, false);
    chassis.waitUntilDone();

    chassis.turnTo(35, 20, 1000);
    chassis.waitUntilDone();

    chassis.follow(defensive_elims_move_from_goal_to_bar_txt, 10, 7000);
    chassis.waitUntilDone();
}

#include "autons.hpp"


ASSET(defensive_qual_move_from_goal_to_bar_txt)
ASSET(defensive_elims_move_from_goal_to_bar_txt)


void Autons::Autons::defensiveQual() {
    Robot::chassis.setPose(42, 60, 135);

    Robot::chassis.moveToPoint(55, 48, 1000);
    Robot::chassis.waitUntilDone();

    Robot::Actions::Flaps::setFlaps(true, false);

    Robot::chassis.moveToPoint(42, 60, 1000, false);
    Robot::chassis.waitUntilDone();

    Robot::Actions::Flaps::setFlaps(false, false);

    Robot::chassis.moveToPose(60, 40, 180, 3000);
    Robot::chassis.waitUntil(10);
    Robot::Actions::Intake::outtake();
    Robot::chassis.waitUntilDone();
    pros::delay(500);
    Robot::Actions::Intake::brake();

    Robot::chassis.turnTo(60, 28, 1000, false);
    Robot::chassis.waitUntilDone();

    Robot::chassis.moveToPose(60, 28, 0, {
        .forwards = false,
        .minSpeed = 110
    });
    Robot::chassis.waitUntilDone();

    Robot::chassis.follow(defensive_qual_move_from_goal_to_bar_txt, 13, 1000);
    Robot::chassis.waitUntilDone();
}


void Autons::Autons::defensiveElims() {
    Robot::chassis.setPose(35, 63, 180);

    Robot::chassis.moveToPoint(35, 10, 3000);
    Robot::chassis.waitUntilDone();

    Robot::chassis.turnTo(45, 10, 1000);
    Robot::chassis.waitUntilDone();

    Robot::Actions::setFlaps(true, true);

    Robot::chassis.moveToPose(5, 10, 90, 2000, {
        .forwards = false,
        .minSpeed = 110
    });
    Robot::chassis.waitUntilDone();

    Robot::Actions::setFlaps(false, false);

    Robot::chassis.moveToPose(45, 10, 90, 2000, {
            .minSpeed = 110
    });
    Robot::chassis.waitUntilDone();

    Robot::chassis.moveToPoint(35, 10, 2000, false);
    Robot::chassis.waitUntilDone();

    Robot::chassis.turnTo(35, 20, 1000);
    Robot::chassis.waitUntilDone();

    Robot::chassis.follow(defensive_elims_move_from_goal_to_bar_txt, 10, 7000);
    Robot::chassis.waitUntilDone();
}

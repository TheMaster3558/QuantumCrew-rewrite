#include "autons.hpp"


ASSET(defensive_elims_move_from_goal_to_bar_txt)


void Autons::nearSideAggressiveAWP() {
    chassis.setPose(-48, -55, 315);

    chassis.moveToPoint(-54, -47, 1000);
    chassis.waitUntilDone();

    Actions::Wings::setRear(true, false);

    chassis.moveToPoint(-48, -55, 1000, false);
    chassis.waitUntilDone();

    chassis.moveToPoint(-58, -40, 3000);
    chassis.waitUntil(5);
    Actions::Wings::setRear(false, false);
    chassis.waitUntilDone();

    chassis.turnTo(-60, -29, 1000);
    chassis.waitUntilDone();

    Actions::Intake::outtake();
    chassis.waitUntilDone();
    pros::delay(500);
    Actions::Intake::brake();

    chassis.turnTo(-60, -28, 1000, false);
    chassis.waitUntilDone();

    chassis.moveToPose(-60, -20, 0, 1000, {
            .forwards = false,
            .maxSpeed = 80,
            .minSpeed = 60
    });
    chassis.waitUntilDone();

    chassis.setPose(-60, -32, chassis.getPose().theta);

    chassis.moveToPose(0, -62, 90, 10000, {
        .maxSpeed = 80
    });
    Autons::utils::waitUntilBelowBar();
}


void Autons::nearSideDisruptAWP() {
    chassis.setPose(Tiles(-1.5), Tiles(-2.5), 0);

    pros::Task task{Autons::utils::runIntake};

    Actions::Wings::setFront(true, false);
    pros::delay(250);
    Actions::Wings::setFront(false, false);

    chassis.moveToPose(0, -10, 90, 3000, {
        .minSpeed = 127
    });
    chassis.waitUntil(10);
    Actions::Wings::setFront(true, true);

    while (chassis.getPose().theta < 80) {
        pros::delay(ez::util::DELAY_TIME);
    }
    chassis.cancelMotion();

    chassis.moveToPoint(10000, -10, 3000);
    while (chassis.getPose().distance(lemlib::Pose(0, -10)) > 10) {
        pros::delay(ez::util::DELAY_TIME);
    }
    chassis.cancelMotion();

    chassis.moveToPoint(-40, -45, 3000);
    chassis.waitUntil(10);
    Actions::Wings::setFront(false, false);
    chassis.waitUntilDone();

    chassis.turnTo(-35, Tiles(-3), 1000);
    chassis.waitUntilDone();

    Actions::Wings::setRear(false, true);

    chassis.tank(35, 127);
    while (chassis.getPose().theta > 110) {
        pros::delay(ez::util::DELAY_TIME);
    }
    chassis.tank(0, 0);

    Actions::Wings::setRear(false, false);
    pros::delay(1000);

    chassis.moveToPose(10, -58, 90, 100000, {
        .maxSpeed = 80
    });
    Autons::utils::waitUntilBelowBar();
}

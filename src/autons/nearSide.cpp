#include "autons.hpp"


ASSET(defensive_elims_move_from_goal_to_bar_txt)


void moveRelative(double distance, int timeout, bool backwards) {
    lemlib::Pose pose = chassis.getPose(true);
    double angle = -pose.theta + M_PI_2;
    double x = std::cos(angle) * distance;
    double y = std::sin(angle) * distance;
    chassis.moveToPoint(pose.x + x, pose.y + y, timeout, backwards);
}


void Autons::nearSideAggressiveAWP() {
    chassis.setPose(-48, -57, 315);
    moveRelative(10, 1000);
    chassis.waitUntilDone();

    Actions::Wings::setRear(true, false);

    moveRelative(-8, 1000, true);
    chassis.waitUntilDone();

    chassis.moveToPoint(-59, -40, 3000);
    chassis.waitUntil(5);
    Actions::Wings::setRear(false, false);
    chassis.waitUntilDone();

    chassis.turnTo(-59, -29, 1000);
    chassis.waitUntilDone();

    Actions::Intake::outtake();
    chassis.waitUntilDone();
    pros::delay(500);
    Actions::Intake::brake();

    chassis.turnTo(-59, -28, 1000, false);
    chassis.waitUntilDone();

    chassis.moveToPose(-59, -28, 0, 1000, {
            .forwards = false,
            .maxSpeed = 80,
            .minSpeed = 60
    });
    chassis.waitUntilDone();

    chassis.setPose(-59, -34, chassis.getPose().theta);

    chassis.moveToPose(-3, -58, 90, 7000);
    chassis.waitUntilDone();
}


void Autons::nearSideDisruptAWP() {
    chassis.setPose(Tiles(-2) - 5, Tiles(-2) - 14, 0);

    chassis.moveToPose(-15, -10, 90, 3000, {
        .lead = 0.8
    });
    while (std::abs(chassis.getPose().theta - 90) > 20) {
        pros::delay(ez::util::DELAY_TIME);
    }
    chassis.cancelMotion();

    chassis.moveToPoint(10000, -5, 3000);
    while (chassis.getPose().distance(lemlib::Pose(0, -5)) > 5) {
        pros::delay(ez::util::DELAY_TIME);
    }
    chassis.cancelMotion();

    chassis.moveToPoint(-53, -53, 3000);
    chassis.waitUntilDone();

    chassis.turnTo(-35, Tiles(-3), 1000);
    chassis.waitUntilDone();

    Actions::Wings::setRear(false, true);

    chassis.tank(35, 127);
    while (std::abs(chassis.getPose().theta) - 90 > 10) {
        pros::delay(ez::util::DELAY_TIME);
    }
    chassis.cancelMotion();

    Actions::Wings::setRear(false, false);
    pros::delay(1000);

    chassis.moveToPose(-3, -58, 90, 7000);
    chassis.waitUntilDone();
}

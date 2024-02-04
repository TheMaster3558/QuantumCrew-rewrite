#include "autons.hpp"


ASSET(offensive_prepare_for_first_ram_txt)
ASSET(offensive_center_outtake_txt)


void Autons::Autons::offensive() {
    chassis.setPose(-13, 59, 0);

    Actions::Intake::intake();
    chassis.moveToPoint(-10, 59, 2000);
    chassis.waitUntilDone();
    Actions::Intake::brake();

    chassis.follow(offensive_prepare_for_first_ram_txt, 15, 3000, false);
    chassis.waitUntil(60);
    chassis.moveToPose(-60, 20, 0, 1000, {
        .forwards = false,
        .minSpeed = 110
    });

    chassis.setPose(-60, 30, 0);

    chassis.follow(offensive_center_outtake_txt, 10, 4000);
    chassis.waitUntilDone();

    Actions::Intake::outtake();
    pros::delay(500);
    Actions::Intake::brake();

    chassis.turnTo(-10, 24, 1000);
    chassis.waitUntilDone();

    Actions::Intake::intake();
    chassis.moveToPoint(-10, 24, 2000);
    chassis.waitUntilDone();
    Actions::Intake::brake();

    chassis.turnTo(-30, 12, 1000);
    chassis.waitUntilDone();

    Actions::Intake::outtake();
    pros::delay(500);
    Actions::Intake::brake();

    chassis.turnTo(-8, 8, 1000);
    chassis.waitUntilDone();

    Actions::Intake::intake();
    chassis.moveToPoint(-8, 8, 2000);
    chassis.waitUntilDone();
    Actions::Intake::brake();

    chassis.turnTo(-50, 8, 1000, false);
    chassis.waitUntilDone();

    Actions::setFlaps(true, true);

    chassis.moveToPose(-50, 8, 90, 3000, {
        .forwards = false,
        .minSpeed = 110
    });
}

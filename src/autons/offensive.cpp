#include "autons.hpp"


ASSET(offensive_elims_take_triball_txt)
ASSET(offensive_qual_move_to_center_txt)
ASSET(offensive_qual_touch_bar_txt)


void Autons::Autons::offensive() {
    chassis.setPose(-10, 60, 90, 1000);

    chassis.moveToPoint(-6, 60, 1000);
    Actions::Intake::intake();
    chassis.waitUntilDone();
    Actions::Intake::brake();

    chassis.moveToPose(-43, 60, 90, 2000, {
        .forwards = false
    });
    chassis.waitUntilDone();

    Actions::Flaps::setFlaps(true, false);

    chassis.moveToPose(-60, 42, 45, 2000, {
        .forwards = false
    });
    chassis.waitUntilDone();

    chassis.turnTo(-60, -30, 1000);
    chassis.waitUntilDone();

    chassis.moveToPose(-60, 30, 180, 1000, {
        .minSpeed = 110
    });
    Actions::Intake::outtake();
    chassis.waitUntilDone();
    Actions::Intake::brake();

    chassis.moveToPoint(-60, 35, 1000, false);
    chassis.waitUntilDone();

    chassis.moveToPose(-10, 25, 100, 4000);
    chassis.waitUntil(15);
    Actions::Intake::intake();
    chassis.waitUntilDone();
    Actions::Intake::brake();

    chassis.turnTo(-47, 9, 1000);
    chassis.waitUntilDone();

    Actions::Intake::outtake();
    pros::delay(1000);
    Actions::Intake::brake();

    chassis.moveToPose(-5, 0, 100, 3000);
    Actions::Intake::intake();
    chassis.waitUntilDone();
    Actions::Intake::brake();

    Actions::Flaps::setFlaps(true, true);

    chassis.moveToPose(-44, 5, 13, 3000, {
        .forwards = false,
        .minSpeed = 110
    });
    chassis.waitUntilDone();

    Actions::Flaps::setFlaps(false, false);

    chassis.moveToPoint(-40, 5, 1000, false);
    chassis.waitUntilDone();

    chassis.turnTo(-44, 5, 1000);
    chassis.waitUntilDone();

    chassis.moveToPose(-44, 5, 270, 2000, {
        .minSpeed = 110
    });
    Actions::Intake::outtake();
    chassis.waitUntilDone();
    Actions::Intake::brake();

    chassis.moveToPoint(-40, 5, 1000, false);
    chassis.waitUntilDone();
}

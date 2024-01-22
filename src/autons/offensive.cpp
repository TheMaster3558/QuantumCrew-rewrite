#include "autons.hpp"


ASSET(offensive_elims_take_triball_txt)
ASSET(offensive_qual_move_to_center_txt)


void Autons::Autons::offensiveQual() {
    Robot::chassis.follow(offensive_qual_move_to_center_txt, 10, 3000);
    Robot::chassis.waitUntilDone();

    Robot::chassis.turnTo(-44, 10, 1000);
    Robot::chassis.waitUntilDone();

    Robot::Actions::Intake::outtake();
    pros::delay(1000);
    Robot::Actins::Intake::brake();

    Robot::chassis.turnTo(-6, 23, 1000);
    Robot::chassis.waitUntilDone();

    Robot::chassis.moveToPoint(-6, 23, 2000);
    Robot::Actions::Intake::intake();
    Robot::chassis.waitUntilDone();
    Robot::Actions::Intake::brake();

    Robot::chassis.moveToPoint(-10, 23, 2000);
    Robot::chassis.waitUntilDone();

    Robot::chassis.turnTo(-44, 10, 1000);
    Robot::chassis.waitUntilDone();

    Robot::Actions::Intake::outtake();
    pros::delay(1000);
    Robot::Actins::Intake::brake();

    Robot::chassis.turnTo(-5, 0, 1000);
    Robot::chassis.waitUntilDone();

    Robot::chassis.moveToPoint(-5, 0, 2000);
    Robot::Actions::Intake::intake();
    Robot::chassis.waitUntilDone();
    Robot::Actions::Intake::brake();


    Robot::chassis.turnTo(-44, 3, 1000);
    Robot::chassis.waitUntilDone();

    setFlaps(true, true);

    Robot::chassis.moveToPose(-44, 3, 100, 3000, {
        .forwards = false,
        .minSpeed = 110
    })
    Robot::chassis.waitUntilDone();

    Robot::chassis.moveToPoint(-40, 0, 1000);
    Robot::chassis.waitUntilDone();

    Robot::chassis.turnTo(-44, 3, 1000);
    Robot::chassis.waitUntilDone();

    Robot::chassis.moveToPose(-44, 3, 100, 2000, {
        .minSpeed = 110
    });
    Robot::Actions::Intake::outtake();
    Robot::chassis.waitUntilDone();
    Robot::Actions::Intake::brake();

    Robot::chassis.moveToPoint(-40, 3, 1000);
    Robot::chassis.waitUntilDone();
}


void Autons::Autons::offensiveElims() {
    Robot::chassis.setPose(-10, 60, 90, 1000);

    Robot::chassis.moveToPoint(-6, 60, 1000);
    Robot::Actions::Intake::intake();
    Robot::chassis.waitUntilDone();
    Robot::Actions::Intake::brake();

    Robot::chassis.moveToPose(-43, 60, 90, 2000, {
        .forwards = false
    });
    Robot::chassis.waitUntilDone();

    Robot::Actions::Flaps::setFlaps(true, false);

    Robot::chassis.moveToPose(-60, 42, 45, 2000, {
        .forwards = false
    });
    Robot::chassis.waitUntilDone();

    Robot::chassis.turnToPoint(-60, -30, 1000);
    Robot::chassis.waitUntilDone();

    Robot::chassis.moveToPose(-60, 30, 180, 1000, {
        .minSpeed = 110
    });
    Robot::Actions::Intake::outake();
    Robot::chassis.waitUntilDone();
    Robot::Actions::Intake::brake();

    Robot::chassis.moveToPoint(-60, 35, 1000, false);
    Robot::chassis.waitUntilDone();

    Robot::chassis.moveToPose(-10, 25, 100, 4000);
    Robot::chassis.waitUntil(15);
    Robot::Actions::Intake::intake();
    Robot::chassis.waitUntilDone();
    Robot::Actions::Intake::brake();

    Robot::chassis.turnTo(-47, 9, 1000);
    Robot::chassis.waitUntilDone();

    Robot::Actions::Intake::outtake();
    pros::delay(1000);
    Robot::Actions::Intake::brake();

    Robot::chassis.moveToPose(-5, 0, 100, 3000);
    Robot::Actions::Intake::intake();
    Robot::chassis.waitUntilDone();
    Robot::Actions::Intake::brake();

    Robot::Actions::Flaps::setFlaps(true, true);

    Robot::chassis.moveToPose(-44, 5, 13, 3000, {
        .forwards = false,
        .minSpeed = 110
    });
    Robot::chassis.waitUntilDone();

    Robot::Actions::Flaps::setFlaps(false, false);

    Robot::chassis.moveToPoint(-40, 5, 1000, false);
    Robot::chassis.waitUntilDone();

    Robot::chassis.turnToPoint(-44, 5, 1000);
    Robot::chassis.waitUntilDone();

    Robot::chassis.moveToPose(-44, 5, 270, 2000, {
        .minSpeed = 110
    });
    Robot::Actions::Intake::outtake();
    Robot::chassis.waitUntilDone();
    Robot::Actions::Intake::brake();

    Robot::chassis.moveToPoint(-40, 5, 1000, false);
    Robot::chassis.waitUntilDone();
}

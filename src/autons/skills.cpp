#include "autons.hpp"


ASSET(skills_move_across_field_txt)
ASSET(skills_move_across_top_field_txt)


void Autons::utils::skillsPushBalls() {
    chassis.setPose(-47, -55, 135);

    chassis.moveToPose(-61, -10, 180, 1000, {
            .forwards = false,
            .minSpeed = 110
    });
    chassis.waitUntilDone();

    chassis.setPose(chassis.getPose().x, -32, 180);

    chassis.moveToPose(-58, -46, 170, 1000);
    chassis.waitUntilDone();

    chassis.turnTo(25, -7, 1000);
    chassis.waitUntilDone();

    chassis.moveToPose(-60, -45, chassis.getPose().theta, 1000, {
        .forwards = false,
        .maxSpeed = 100
    });
    chassis.waitUntilDone();
}


void Autons::utils::skillsBarrierBalls() {
    chassis.moveToPoint(-25, -35, 1000);
    chassis.waitUntilDone();

    Actions::Wings::setFront(true, false);

    chassis.moveToPoint(-20, 33, 5000);
    chassis.waitUntilDone();

    Actions::Wings::setFront(false, false);

    chassis.moveToPose(-45, 51, 45, 5000);
    chassis.waitUntil(30);
    chassis.cancelMotion();
}


void Autons::skills() {
    Autons::utils::skillsPushBalls();

    Actions::Wings::setRear(false, true);

    lemlib::Pose beforeMatchLoad = chassis.getPose();
    Actions::Catapult::lower();
    pros::delay(25000);
    Actions::Catapult::brake();
    chassis.setPose(beforeMatchLoad);

    Actions::Wings::setRear(false, false);
    pros::delay(1000);

    Autons::utils::skillsBarrierBalls();

    chassis.follow(skills_move_across_top_field_txt, 13, 5000);
    chassis.waitUntil(100);
    Actions::Wings::setFront(true, true);
    chassis.waitUntil(120);
    Actions::Wings::setFront(false, false);
    chassis.waitUntilDone();

    chassis.setPose(60, 25, chassis.getPose().theta);

    chassis.tank(-40, -40);
    pros::delay(400);

    chassis.tank(110, 100);
    pros::delay(750);

    chassis.setPose(60, 25, 180);

    chassis.tank(-50, -50);
    pros::delay(1250);
    Actions::Intake::brake();

    chassis.moveToPoint(14, 28, 3000);
    chassis.waitUntilDone();

    chassis.moveToPose(60, 12, 90, 2000, {
            .lead = 0.7,
            .minSpeed = 110
    });
    chassis.waitUntil(7);
    Actions::Wings::setFront(true, true);
    Actions::Intake::outtake();
    chassis.waitUntilDone();

    chassis.tank(-75, -75);
    pros::delay(500);

    chassis.moveToPoint(100, chassis.getPose().y, 1000);
    chassis.waitUntilDone();

    Actions::Intake::brake();

    chassis.setPose(47, 9, chassis.getPose().theta);

    Actions::Wings::setFront(false, false);

    chassis.moveToPose(14, 32, 180, 3000, {
        .forwards = false,
        .minSpeed = 110
    });
    chassis.waitUntilDone();

    chassis.moveToPoint(10, -28, 3000);
    chassis.waitUntilDone();

    Actions::Wings::setRear(true, true);

    chassis.turnTo(10000, chassis.getPose().y, 1000, false);
    chassis.waitUntilDone();

    chassis.moveToPose(60, 0, 270, 1500, {
            .forwards = false,
            .lead = 0.7,
            .minSpeed = 110
    });
    chassis.waitUntilDone();

    chassis.tank(50, 50);
    pros::delay(500);
    chassis.tank(-100, -100);
    pros::delay(750);
    chassis.tank(0, 0);

    chassis.setPose(40, chassis.getPose().y, 270);

    chassis.moveToPoint(33, chassis.getPose().y, 3000);
    chassis.waitUntilDone();

    Actions::Wings::setRear(false, false);

    chassis.moveToPose(38, -67, 180, 2000);
    chassis.waitUntilDone();

    chassis.moveToPose(60, -7, 0, 3000);
    chassis.waitUntil(10);
    Actions::Wings::setFront(true, true);
    Actions::Intake::outtake();
    chassis.waitUntilDone();

    chassis.tank(-50, -50);
    pros::delay(200);

    Actions::Wings::setFront(false, false);

    pros::delay(500);

    chassis.tank(127, 100);
    pros::delay(750);

    chassis.tank(-50, -50);
    pros::delay(500);
    chassis.tank(0, 0);

    Actions::Intake::brake();
}

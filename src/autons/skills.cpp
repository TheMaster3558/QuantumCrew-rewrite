#include "autons.hpp"


ASSET(skills_first_ram_txt)
ASSET(skills_prepare_for_second_ram_txt)
ASSET(skills_prepare_for_final_ram_txt)


void Autons::Autons::skills() {
    chassis.setPose(-45, -58, 150);

    chassis.moveToPose(-60, -28, 180, 3000, {
        .forwards = false,
        .minSpeed = 110
    });
    chassis.waitUntilDone();

    chassis.moveToPose(-53, -53, 54, 4000, {
        .forwards = false
    });
    chassis.waitUntilDone();

    Actions::Catapult::lower();
    pros::delay(40000);

    Motors::catapult.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    pros::Task lowerCatapult(Actions::Catapult::moveToHoldAngle);

    chassis.moveToPose(-48, -48, 54, 2000);
    chassis.waitUntilDone();

    chassis.follow(skills_first_ram_txt, 10, 10000, false);
    chassis.waitUntilDone();

    chassis.follow(skills_prepare_for_second_ram_txt, 13, 5000);
    chassis.waitUntilDone();

    Actions::Flaps::setFlaps(true, true);

    chassis.moveToPose(42, -7, 260, 2000, {
        .forwards = false,
        .minSpeed = 110
    });
    chassis.waitUntilDone();

    chassis.moveToPose(10, 13, 290, 2000);
    chassis.waitUntilDone();

    chassis.moveToPose(42, 9, 280, 2000, {
        .forwards = false,
        .minSpeed = 110
    });
    chassis.waitUntilDone();

    chassis.moveToPose(30, 10, 290, 2000);
    chassis.waitUntilDone();

    chassis.moveToPose(42, 9, 280, 2000, {
        .forwards = false,
        .minSpeed = 110
    });
    chassis.waitUntilDone();

    Actions::Flaps::setFlaps(false, false);

    chassis.follow(skills_prepare_for_final_ram_txt, 13, 5000);
    chassis.waitUntilDone();

    chassis.moveToPose(58, 27, 350, 2000, {
        .forwards = false,
        .minSpeed = 110
    });
    chassis.waitUntil(10);
    Actions::Flaps::setFlaps(true, true);
    chassis.waitUntilDone();

    Motors::catapult.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
}

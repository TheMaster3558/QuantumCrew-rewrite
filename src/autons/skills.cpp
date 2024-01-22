#include "autons.hpp"


ASSET(skills_first_ram_txt)
ASSET(skills_prepare_for_second_ram_txt)
ASSET(skills_prepare_for_final_ram_txt)


void Autons::Autons::skills() {
    Robot::chassis.setPose(-45, -58, 150);

    Robot::chassis.moveToPose(-60, -28, 180, 3000, {
        .forwards = false,
        .minSpeed = 110
    });
    Robot::chassis.waitUntilDone();

    Robot::chassis.moveToPose(-53, -53, 54, 4000, {
        .forwards = false
    });
    Robot::chassis.waitUntilDone();

    Robot::Actions::Catapult::lower();
    pros::delay(40000);

    Robot::Motors::catapult.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    pros::Task lowerCatapult(Robot::Actions::Catapult::moveToHoldAngle);

    Robot::chassis.moveToPose(-48, -48, 54, 2000);
    Robot::chassis.waitUntilDone();

    Robot::chassis.follow(skills_first_ram_txt, 10, 10000, false);
    Robot::chassis.waitUntilDone();

    Robot::chassis.follow(skills_prepare_for_second_ram_txt, 13, 5000);
    Robot::chassis.waitUntilDone();

    Robot::Actions::Flaps::setFlaps(true, true);

    Robot::chassis.moveToPose(42, -7, 260, 2000, {
        .forwards = false,
        .minSpeed = 110
    });
    Robot::chassis.waitUntilDone();

    Robot::chassis.moveToPose(10, 13, 290, 2000);
    Robot::chassis.waitUntilDone();

    Robot::chassis.moveToPose(42, 9, 280, 2000, {
        .forwards = false,
        .minSpeed = 110
    });
    Robot::chassis.waitUntilDone();

    Robot::chassis.moveToPose(30, 10, 290, 2000);
    Robot::chassis.waitUntilDone();

    Robot::chassis.moveToPose(42, 9, 280, 2000, {
            .forwards = false,
            .minSpeed = 110
    });
    Robot::chassis.waitUntilDone();

    Robot::Actions::Flaps::setFlaps(false, false);

    Robot::chassis.follow(skills_prepare_for_final_ram_txt, 13, 5000);
    Robot::chassis.waitUntilDone();

    Robot::chassis.moveToPose(58, 27, 350, 2000, {
        .forwards = false,
        .minSpeed = 110
    });
    Robot::chassis.waitUntil(10);
    Robot::Actions::Flaps::setFlaps(true, true);
    Robot::chassis.waitUntilDone();

    Robot::Motors::catapult.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
}

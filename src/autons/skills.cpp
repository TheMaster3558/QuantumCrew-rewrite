#include "autons.hpp"


ASSET(skills_prepare_for_first_ram_txt)
ASSET(skills_first_ram_to_second_txt)


void Autons::Autons::skills() {
    /*
    chassis.setPose(-50, -55, 240);

    Actions::Catapult::lower();
    pros::delay(42000);
    Actions::Catapult::brake();

    Motors::catapult.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    pros::Task moveCatapultDown(Actions::Catapult::moveToHoldAngle);

    chassis.moveToPoint(30, -55, 3000, false);
    chassis.waitUntil(85);
    chassis.cancelMotion();

    chassis.moveToPoint(58, -25, 3000, false);
    chassis.waitUntil(35);
    chassis.cancelMotion();

    chassis.moveToPoint(50, -15, 1000, false);
    chassis.waitUntilDone();

    chassis.setPose(55, -30, 180);

    chassis.follow(skills_first_ram_to_second_txt, 10, 4000);
    chassis.waitUntilDone();

    chassis.turnTo(50, -10, 1000, false);
    chassis.waitUntilDone();

    Actions::Flaps::setFlaps(true, true);

    chassis.moveToPoint(50, -8, 3000, false);
    chassis.waitUntilDone();

    chassis.setPose(42, -10, 270);

    chassis.moveToPoint(37, -10, 3000, false);
    chassis.waitUntilDone();

    chassis.moveToPoint(50, -10, 3000, false);
    chassis.waitUntilDone();

    chassis.setPose(42, -10, 270);

    chassis.moveToPoint(18, -8, 2000);
    chassis.waitUntil(4);
    Actions::Flaps::setFlaps(false, false);
    chassis.waitUntilDone();

    chassis.moveToPoint(20, 8, 2000);
    chassis.waitUntilDone();

    chassis.turnTo(50, 8, 1000, false);
    chassis.waitUntilDone();

    Actions::Flaps::setFlaps(true, true);

    chassis.moveToPose(55, 8, 270, 5000, {
            .forwards = false,
            .minSpeed= 110
    });

    Motors::catapult.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
     */
}

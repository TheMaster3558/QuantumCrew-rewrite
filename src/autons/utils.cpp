#include "autons.hpp"


void Autons::utils::runIntake() {
    Actions::Intake::outtake();
    pros::delay(500);
    Actions::Intake::brake();
}


void Autons::utils::waitUntilBelowBar() {
    Motors::leftDrive.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
    Motors::rightDrive.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);

    while (Sensors::intakeDistanceSensor.get() > 500 && chassis.isInMotion()) {
        pros::delay(ez::util::DELAY_TIME);
    }
    chassis.cancelMotion();
    chassis.tank(0, 0);

    pros::delay(500);
    Motors::leftDrive.set_brake_modes(pros::E_MOTOR_BRAKE_COAST);
    Motors::rightDrive.set_brake_modes(pros::E_MOTOR_BRAKE_COAST);
}

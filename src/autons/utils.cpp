#include "autons.hpp"


void Autons::utils::moveRelative(double distance, int timeout, bool forwards) {
    lemlib::Pose pose = chassis.getPose(true);
    double angle = -pose.theta + M_PI_2;
    double x = std::cos(angle) * distance;
    double y = std::sin(angle) * distance;
    chassis.moveToPoint(pose.x + x, pose.y + y, timeout, forwards);
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

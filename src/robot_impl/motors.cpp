#include "pros/motors.hpp"
#include "robot.hpp"

pros::Motor leftFront(2, pros::E_MOTOR_GEAR_BLUE, true);
pros::Motor leftMiddle(3, pros::E_MOTOR_GEAR_BLUE);
pros::Motor leftBack(7, pros::E_MOTOR_GEAR_BLUE, true);

pros::Motor rightFront(4, pros::E_MOTOR_GEAR_BLUE);
pros::Motor rightMiddle(5, pros::E_MOTOR_GEAR_BLUE, true);
pros::Motor rightBack(6, pros::E_MOTOR_GEAR_BLUE);

pros::Motor Robot::Motors::intake(1, pros::E_MOTOR_GEAR_GREEN);
pros::Motor Robot::Motors::catapult(8, pros::E_MOTOR_GEAR_RED);

pros::MotorGroup Robot::Motors::leftDrive({leftFront, leftMiddle, leftBack});
pros::MotorGroup Robot::Motors::rightDrive({rightFront, rightMiddle, rightBack});

void Robot::Motors::setDriveBrake(pros::motor_brake_mode_e_t mode) {
    Robot::Motors::leftDrive.set_brake_modes(mode);
    Robot::Motors::rightDrive.set_brake_modes(mode);
}

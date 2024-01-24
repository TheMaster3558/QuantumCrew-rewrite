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


void printOverheatingMotor(std::string name, pros::Motor motor, int* line) {
    if (motor.is_over_temp()) {
        std::ostringstream formattedString;
        formattedString << name << " motor (port " << motor.get_port() << ") overheating: " << motor.get_temperature() << "C";

        ez::print_to_screen(formattedString.str(), (*line)++);
    }
}


void Robot::Motors::printOverheatingMotors() {
    pros::lcd::clear();
    int line = 0;

    printOverheatingMotor("Intake", intake, &line);
    printOverheatingMotor("Catapult", catapult, &line);
    printOverheatingMotor("Left Front Drive", leftFront, &line);
    printOverheatingMotor("Left Middle Drive", leftMiddle, &line);
    printOverheatingMotor("Left Back Drive", leftBack, &line);
    printOverheatingMotor("Right Front Drive", rightFront, &line);
    printOverheatingMotor("Right Middle Drive", rightMiddle, &line);
    printOverheatingMotor("Right Back Drive", rightBack, &line);
}

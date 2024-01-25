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


void printOverheatingMotor(std::string name, pros::Motor motor, int& line, std::vector<int>& overheatingMotors) {
    if (motor.is_over_temp()) {
        std::ostringstream formattedString;
        formattedString << name << " motor (port " << motor.get_port() << ") overheating: " << motor.get_temperature() << "C";
        ez::print_to_screen(formattedString.str(), line++);

        overheatingMotors.push_back(motor.get_port());
    }
}


const char* joinVector(std::vector<int> vector, std::string delim) {
    std::ostringstream str;
    for (auto &i : vector) {
        str << i << delim;
    }
    str.seekp(-delim.size(), std::ios_base::end);
    str << '\0';
    return str.str().c_str();
}


void Robot::Motors::printOverheatingMotors() {
    pros::lcd::clear();
    int line = 0;
    std::vector<int> overheatingMotors;

    printOverheatingMotor("Intake", intake, line, overheatingMotors);
    printOverheatingMotor("Catapult", catapult, line, overheatingMotors);
    printOverheatingMotor("Left Front Drive", leftFront, line, overheatingMotors);
    printOverheatingMotor("Left Middle Drive", leftMiddle, line, overheatingMotors);
    printOverheatingMotor("Left Back Drive", leftBack, line, overheatingMotors);
    printOverheatingMotor("Right Front Drive", rightFront, line, overheatingMotors);
    printOverheatingMotor("Right Middle Drive", rightMiddle, line, overheatingMotors);
    printOverheatingMotor("Right Back Drive", rightBack, line, overheatingMotors);

    if (overheatingMotors.size() > 0) {
        Robot::controller.print(0, 0, "Overheating Motors: %s", joinVector(overheatingMotors, ", "));
    }
    else {
        Robot::controller.print(0, 0, "");
    }
}

#include "robot.hpp"


pros::Motor leftFront(LEFT_FRONT_DRIVE_PORT, pros::E_MOTOR_GEAR_BLUE);
pros::Motor leftBackBottom(LEFT_BACK_BOTTOM_DRIVE_PORT, pros::E_MOTOR_GEAR_BLUE);
pros::Motor leftBackTop(LEFT_BACK_TOP_DRIVE_PORT, pros::E_MOTOR_GEAR_BLUE);

pros::Motor rightFront(RIGHT_FRONT_DRIVE_PORT, pros::E_MOTOR_GEAR_BLUE);
pros::Motor rightBackBottom(RIGHT_BACK_BOTTOM_DRIVE_PORT, pros::E_MOTOR_GEAR_BLUE);
pros::Motor rightBackTop(RIGHT_BACK_TOP_DRIVE_PORT, pros::E_MOTOR_GEAR_BLUE);

pros::Motor Robot::Motors::intake(INTAKE_PORT, pros::E_MOTOR_GEAR_GREEN);
pros::Motor Robot::Motors::catapult(CATAPULT_PORT, pros::E_MOTOR_GEAR_RED);

pros::MotorGroup Robot::Motors::leftDrive({leftFront, leftBackBottom, leftBackTop});
pros::MotorGroup Robot::Motors::rightDrive({rightFront, rightBackBottom, rightBackTop});

void Robot::Motors::setDriveBrake(pros::motor_brake_mode_e_t mode) {
    Robot::Motors::leftDrive.set_brake_modes(mode);
    Robot::Motors::rightDrive.set_brake_modes(mode);
}


void addOverheatingMotor(pros::Motor motor, std::vector<int>& overheatingMotors) {
    if (motor.is_over_temp()) {
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
    std::vector<int> overheatingMotors;

    addOverheatingMotor(intake, overheatingMotors);
    addOverheatingMotor(catapult, overheatingMotors);
    addOverheatingMotor(leftFront, overheatingMotors);
    addOverheatingMotor(leftBackBottom, overheatingMotors);
    addOverheatingMotor(leftBackTop, overheatingMotors);
    addOverheatingMotor(rightFront, overheatingMotors);
    addOverheatingMotor(rightBackBottom, overheatingMotors);
    addOverheatingMotor(rightBackTop, overheatingMotors);

    if (overheatingMotors.size() > 0) {
        Robot::controller.print(0, 0, joinVector(overheatingMotors, ", "));
    } else {
        Robot::controller.print(0, 0, "");
    }

}

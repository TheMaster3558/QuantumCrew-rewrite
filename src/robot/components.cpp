#include "pros/rotation.hpp"
#include "pros/adi.hpp"
#include "robot.hpp"


pros::Motor leftFront(LEFT_FRONT_DRIVE_PORT, pros::E_MOTOR_GEAR_BLUE);
pros::Motor leftBackBottom(LEFT_BACK_BOTTOM_DRIVE_PORT, pros::E_MOTOR_GEAR_BLUE);
pros::Motor leftBackTop(LEFT_BACK_TOP_DRIVE_PORT, pros::E_MOTOR_GEAR_BLUE);

pros::Motor rightFront(RIGHT_FRONT_DRIVE_PORT, pros::E_MOTOR_GEAR_BLUE);
pros::Motor rightBackBottom(RIGHT_BACK_BOTTOM_DRIVE_PORT, pros::E_MOTOR_GEAR_BLUE);
pros::Motor rightBackTop(RIGHT_BACK_TOP_DRIVE_PORT, pros::E_MOTOR_GEAR_BLUE);

pros::Motor Motors::intake(INTAKE_PORT, pros::E_MOTOR_GEAR_GREEN);
pros::Motor Motors::catapult(CATAPULT_PORT, pros::E_MOTOR_GEAR_RED);

pros::MotorGroup Motors::leftDrive({leftFront, leftBackBottom, leftBackTop});
pros::MotorGroup Motors::rightDrive({rightFront, rightBackBottom, rightBackTop});


void Motors::setDriveBrake(pros::motor_brake_mode_e_t mode) {
    Motors::leftDrive.set_brake_modes(mode);
    Motors::rightDrive.set_brake_modes(mode);
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


void Motors::printOverheatingMotors() {
    std::vector<int> overheatingMotors;

    addOverheatingMotor(intake, overheatingMotors);
    addOverheatingMotor(catapult, overheatingMotors);
    addOverheatingMotor(leftFront, overheatingMotors);
    addOverheatingMotor(leftBackBottom, overheatingMotors);
    addOverheatingMotor(leftBackTop, overheatingMotors);
    addOverheatingMotor(rightFront, overheatingMotors);
    addOverheatingMotor(rightBackBottom, overheatingMotors);
    addOverheatingMotor(rightBackTop, overheatingMotors);

    controller.print(0, 0, joinVector(overheatingMotors, ", "));

}


ez::Piston Pistons::frontLeftWing(FRONT_LEFT_WING_PORT);
ez::Piston Pistons::frontRightWing(FRONT_RIGHT_WING_PORT);
ez::Piston Pistons::rearLeftWing(REAR_LEFT_WING_PORT);
ez::Piston Pistons::rearRightWing(REAR_RIGHT_WING_PORT);


pros::Imu Sensors::imuSensor(IMU_PORT);
pros::Rotation Sensors::catapultRotationSensor(CATAPULT_ROTATION_SENSOR_PORT);
pros::Distance Sensors::intakeDistanceSensor(INTAKE_DISTANCE_SENSOR_PORT);


int Sensors::getCatapultAngle() {
    return Sensors::catapultRotationSensor.get_angle() / 100;
}


float Sensors::getIntakeUpInches() {
    return Sensors::intakeDistanceSensor.get() * 0.0393701;
}


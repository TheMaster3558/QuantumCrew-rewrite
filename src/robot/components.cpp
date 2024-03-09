#include "pros/rotation.hpp"
#include "pros/adi.hpp"
#include "robot.hpp"


pros::Motor leftFront(LEFT_FRONT_DRIVE_PORT, pros::E_MOTOR_GEAR_BLUE);
pros::Motor leftBackBottom(LEFT_BACK_BOTTOM_DRIVE_PORT, pros::E_MOTOR_GEAR_BLUE);
pros::Motor leftBackTop(LEFT_BACK_TOP_DRIVE_PORT, pros::E_MOTOR_GEAR_BLUE);

pros::Motor rightFront(RIGHT_FRONT_DRIVE_PORT, pros::E_MOTOR_GEAR_BLUE);
pros::Motor rightBackBottom(RIGHT_BACK_BOTTOM_DRIVE_PORT, pros::E_MOTOR_GEAR_BLUE);
pros::Motor rightBackTop(RIGHT_BACK_TOP_DRIVE_PORT, pros::E_MOTOR_GEAR_BLUE);

pros::MotorGroup Motors::intake({INTAKE_PORTS});
pros::MotorGroup Motors::catapult({CATAPULT_PORTS});

pros::MotorGroup Motors::leftDrive({leftFront, leftBackBottom, leftBackTop});
pros::MotorGroup Motors::rightDrive({rightFront, rightBackBottom, rightBackTop});

ez::Piston Pistons::frontLeftWing(FRONT_LEFT_WING_PORT);
ez::Piston Pistons::frontRightWing(FRONT_RIGHT_WING_PORT);
ez::Piston Pistons::rearLeftWing(REAR_LEFT_WING_PORT);
ez::Piston Pistons::rearRightWing(REAR_RIGHT_WING_PORT);


pros::Imu Sensors::imuSensor(IMU_PORT);
pros::Distance Sensors::intakeDistanceSensor(INTAKE_DISTANCE_SENSOR_PORT);

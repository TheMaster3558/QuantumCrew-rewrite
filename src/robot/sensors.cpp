#include "pros/imu.hpp"
#include "pros/rotation.hpp"
#include "robot.hpp"


pros::Imu Robot::Sensors::imuSensor(9);
pros::Rotation Robot::Sensors::catapultRotationSensor(10);

int Robot::Sensors::getCatapultAngle() {
    return Robot::Sensors::catapultRotationSensor.get_angle() / 100;
}

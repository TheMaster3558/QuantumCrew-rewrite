#include "pros/imu.hpp"
#include "pros/rotation.hpp"
#include "robot.hpp"


pros::Imu Robot::Sensors::imuSensor(IMU_PORT);
pros::Rotation Robot::Sensors::catapultRotationSensor(CATAPULT_ROTATION_SENSOR_PORT);

int Robot::Sensors::getCatapultAngle() {
    return Robot::Sensors::catapultRotationSensor.get_angle() / 100;
}

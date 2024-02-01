#include "robot.hpp"


// forward/backward PID
lemlib::ControllerSettings Robot::Tunables::linearController(
    10, // proportional gain (kP),
    0, // integral gain (kI)
    30, // derivative gain (kD)
    0, // windup range
    1, // small error range, in inches
    100, // small error range timeout, in milliseconds
    3, // large error range, in inches
    500, // large error range timeout, in milliseconds
    20 // maximum acceleration (slew)
);

// turning PID
lemlib::ControllerSettings Robot::Tunables::angularController(
    2, // proportional gain (kP)
    0, // integral gain (kI)
    10, // derivative gain (kD)
    0, // windup range
    1, // small error range, in degrees
    100, // small error range timeout, in milliseconds
    3, // large error range, in degrees
    500, // large error range timeout, in milliseconds
    0 // maximum acceleration (slew). 0 means no limit
);

const int Robot::Tunables::chasePower = 8;
int Robot::Tunables::catapultVelocity = CATAPULT_VELOCITY;
int Robot::Tunables::catapultHoldAngle = CATAPULT_HOLD_ANGLE;

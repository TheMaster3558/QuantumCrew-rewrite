#include "robot.hpp"


const int Tunables::chasePower = 8;
int Tunables::driveCurve = 4;
int Tunables::catapultVelocity = 115;


const float DrivetrainInfo::drivetrainWidth = 11.0;
const float DrivetrainInfo::wheelDiameter = lemlib::Omniwheel::NEW_325;
const int DrivetrainInfo::drivetrainRpm = 360;


// forward/backward PID
lemlib::ControllerSettings Tunables::linearController(
        30, // proportional gain (kP),
        0, // integral gain (kI)
        60, // derivative gain (kD)
        0, // windup range
        1, // small error range, in inches
        100, // small error range timeout, in milliseconds
        3, // large error range, in inches
        500, // large error range timeout, in milliseconds
        40 // maximum acceleration (slew)
);

// turning PID
lemlib::ControllerSettings Tunables::angularController(
        4, // proportional gain (kP)
        0, // integral gain (kI)
        36, // derivative gain (kD)
        0, // windup range
        1, // small error range, in degrees
        100, // small error range timeout, in milliseconds
        3, // large error range, in degrees
        500, // large error range timeout, in milliseconds
        0 // maximum acceleration (slew). 0 means no limit
);


lemlib::Drivetrain drivetrain {
    &Motors::leftDrive,
    &Motors::rightDrive,
    DrivetrainInfo::drivetrainWidth,
    DrivetrainInfo::wheelDiameter,
    DrivetrainInfo::drivetrainRpm,
    Tunables::chasePower
};


lemlib::OdomSensors sensors {
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    &Sensors::imuSensor
};


lemlib::Chassis chassis {
    drivetrain,
    Tunables::linearController,
    Tunables::angularController,
    sensors
};

pros::Controller controller(pros::E_CONTROLLER_MASTER);

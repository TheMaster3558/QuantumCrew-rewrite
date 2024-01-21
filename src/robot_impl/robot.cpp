#include "robot.hpp"


lemlib::Drivetrain drivetrain {
        &Robot::Motors::leftDrive,
        &Robot::Motors::rightDrive,
        Robot::DrivetrainInfo::drivetrainWidth,
        Robot::DrivetrainInfo::wheelDiameter,
        Robot::DrivetrainInfo::drivetrainRpm,
        Robot::Tunables::chasePower
};


lemlib::OdomSensors sensors {
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    &Robot::Sensors::imuSensor
};


lemlib::Chassis Robot::chassis {
    drivetrain,
    Robot::Tunables::linearController,
    Robot::Tunables::angularController,
    sensors
};

pros::Controller Robot::controller{pros::E_CONTROLLER_MASTER};

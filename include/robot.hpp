#pragma once

#include <sstream>
#include <vector>
#include "pros/misc.hpp"
#include "pros/motors.hpp"
#include "pros/adi.hpp"
#include "pros/rotation.hpp"
#include "pros/imu.hpp"
#include "pros/llemu.hpp"
#include "lemlib/api.hpp"
#include "config.h"


class Robot {
public:
    class Motors {
    public:
        static pros::MotorGroup leftDrive;
        static pros::MotorGroup rightDrive;

        static void setDriveBrake(pros::motor_brake_mode_e_t mode);

        static pros::Motor intake;
        static pros::Motor catapult;

        static void printOverheatingMotors();
    };

    class Pistons {
    public:
        static pros::ADIDigitalOut leftFlap;
        static pros::ADIDigitalOut rightFlap;
    };

    class Sensors {
    public:
        static pros::Imu imuSensor;
        static pros::Rotation catapultRotationSensor;

        static int getCatapultAngle();
    };

    class DrivetrainInfo {
    public:
        static constexpr float drivetrainWidth = 13.5;
        static constexpr float wheelDiameter = lemlib::Omniwheel::NEW_325;
        static constexpr int drivetrainRpm = 360;
    };

    class Tunables {
    public:
        static lemlib::ControllerSettings linearController;
        static lemlib::ControllerSettings angularController;
        static const int chasePower;

        static int catapultVelocity;
        static int catapultHoldAngle;
    };

    class Actions {
    public:
        class Flaps {
        public:
            static bool leftFlapState;
            static bool rightFlapState;

            static void setFlaps(bool, bool);
            static void reverseFlaps();
        };

        class Intake {
        public:
            static void intake();
            static void outtake();
            static void brake();
        };

        class Catapult {
        public:
            static lemlib::PID catapultPID;

            static void lower();
            static void stepToHoldAngle();
            static void moveToHoldAngle();
            static void brake();
        };
    };


    static pros::Controller controller;
    static lemlib::Chassis chassis;
};

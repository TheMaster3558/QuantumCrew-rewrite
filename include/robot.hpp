#pragma once

#include <sstream>
#include <vector>
#include <utility>
#include "pros/misc.hpp"
#include "pros/motors.hpp"
#include "pros/adi.hpp"
#include "pros/rotation.hpp"
#include "pros/imu.hpp"
#include "pros/llemu.hpp"
#include "lemlib/api.hpp"
#include "config.h"


namespace Motors {
    extern pros::MotorGroup leftDrive;
    extern pros::MotorGroup rightDrive;

    void setDriveBrake(pros::motor_brake_mode_e_t mode);

    extern pros::Motor intake;
    extern pros::Motor catapult;

    void printOverheatingMotors();
}

namespace Pistons {
    extern pros::ADIDigitalOut frontLeftFlap;
    extern pros::ADIDigitalOut frontRightFlap;
    extern pros::ADIDigitalOut backLeftFlap;
    extern pros::ADIDigitalOut backRightFlap;
}

namespace Sensors {
    extern pros::Imu imuSensor;
    extern pros::Rotation catapultRotationSensor;

    int getCatapultAngle();
}

namespace DrivetrainInfo {
    extern const float drivetrainWidth;
    extern const float wheelDiameter;
    extern const int drivetrainRpm;
}

namespace Tunables {
    extern lemlib::ControllerSettings linearController;
    extern lemlib::ControllerSettings angularController;
    extern const int chasePower;

    extern int catapultVelocity;
    extern int catapultHoldAngle;
}

enum Flap { FRONT, BACK };

typedef std::pair<bool, bool> FlapState;
#define makeFlapState(left, right) (std::make_pair(left, right))

namespace Actions {
    namespace Flaps {
        void setFlaps(Flap, FlapState);
        void reverseFlaps(Flap);
    }

    namespace Intake {
        void intake();
        void outtake();
        void brake();
    }

    namespace Catapult {
        void lower();
        void stepToHoldAngle();
        void moveToHoldAngle();
        void brake();
    }

}

extern pros::Controller controller;
extern lemlib::Chassis chassis;

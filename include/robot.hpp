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
#include "EZ-Template/api.hpp"
#include "config.h"


namespace Motors {
    extern pros::MotorGroup leftDrive;
    extern pros::MotorGroup rightDrive;

    extern pros::MotorGroup intake;
    extern pros::MotorGroup catapult;
}

namespace Pistons {
    extern ez::Piston frontLeftWing;
    extern ez::Piston frontRightWing;
    extern ez::Piston rearLeftWing;
    extern ez::Piston rearRightWing;
}

namespace Sensors {
    extern pros::Imu imuSensor;
    extern pros::Distance intakeDistanceSensor;

    float getIntakeUpInches();
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

    extern int driveCurve;
    extern int catapultVelocity;
}

namespace Actions {
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

    namespace Wings {
        void setFront(bool, bool);
        void setRear(bool, bool);
    }
}

extern pros::Controller controller;
extern lemlib::Chassis chassis;

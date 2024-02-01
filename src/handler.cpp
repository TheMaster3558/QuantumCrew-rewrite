#include "handler.hpp"
#include "robot.hpp"


void EventHandler::handleFlaps() {
    if (Robot::controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
        Robot::Actions::Flaps::reverseFlaps();
    }
}


void EventHandler::handleCatapult() {
    if (Robot::controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
        Robot::Actions::Catapult::lower();
    } else if (Robot::controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
        Robot::Motors::catapult.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        Robot::Actions::Catapult::stepToHoldAngle();
    } else {
        Robot::Motors::catapult.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
        Robot::Actions::Catapult::brake();
    }

    if (Robot::controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)) {
        Robot::Tunables::catapultVelocity--;
    }
    if (Robot::controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
        Robot::Tunables::catapultVelocity++;
    }
}


void EventHandler::handleIntake() {
    if (Robot::controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
        Robot::Actions::Intake::outtake();
    } else if (Robot::controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
        Robot::Actions::Intake::intake();
    } else {
        Robot::Actions::Intake::brake();
    }
}


void EventHandler::updateDisplay() {
    static int counter = 0;
    if (counter++ % (50 / ez::util::DELAY_TIME) == 0) {
        //Robot::Motors::printOverheatingMotors();
    }
}


void EventHandler::updateCalibration() {
    if (Robot::controller.get_digital(pros::E_CONTROLLER_DIGITAL_X) &&
        Robot::controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y) &&
        Robot::controller.get_digital(pros::E_CONTROLLER_DIGITAL_A)
    ) {
        Robot::chassis.calibrate();
    }
}


void EventHandler::handleAll() {
    EventHandler::handleFlaps();
    EventHandler::handleCatapult();
    EventHandler::handleIntake();
    EventHandler::updateDisplay();
    EventHandler::updateCalibration();
}



#include "handler.hpp"
#include "robot.hpp"


void EventHandler::handleWings() {
    Pistons::frontWings.button_toggle(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X));
    Pistons::backWings.button_toggle(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B));
}


void EventHandler::handleCatapult() {
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
        Actions::Catapult::lower();
    } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
        Motors::catapult.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        Actions::Catapult::stepToHoldAngle();
    } else {
        Motors::catapult.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
        Actions::Catapult::brake();
    }

    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)) {
        Tunables::catapultVelocity--;
    }
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
        Tunables::catapultVelocity++;
    }
}


void EventHandler::handleIntake() {
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
        Actions::Intake::outtake();
    } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
        Actions::Intake::intake();
    } else {
        Actions::Intake::brake();
    }
}


void EventHandler::updateDisplay() {
    static int counter = 0;
    if (counter++ % (50 / ez::util::DELAY_TIME) == 0) {
        Motors::printOverheatingMotors();
    }
}


void EventHandler::handleAll() {
    EventHandler::handleWings();
    EventHandler::handleCatapult();
    EventHandler::handleIntake();
    EventHandler::updateDisplay();
}



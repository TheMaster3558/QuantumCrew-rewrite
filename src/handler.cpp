#include "handler.hpp"
#include "robot.hpp"


void EventHandler::handleWings() {
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
        Pistons::frontLeftWing.set(true);
        Pistons::frontRightWing.set(true);
    }
    else {
        Pistons::frontLeftWing.set(false);
        Pistons::frontRightWing.set(false);
    }
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
        Pistons::rearLeftWing.set(true);
        Pistons::rearRightWing.set(true);
    }
    else {
        Pistons::rearLeftWing.set(false);
        Pistons::rearRightWing.set(false);
    }
}


void EventHandler::handleCatapult() {
    static bool autoLaunch = false;
    static bool autoHold = false;

    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
        autoLaunch = !autoLaunch;
    }
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) {
        autoHold = !autoHold;
    }

    if (autoLaunch || controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
        Actions::Catapult::lower();
    }
    else if (autoHold) {
        Actions::Catapult::stepToHoldAngle();
    }
    else {
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
        //Motors::printOverheatingMotors();
    }
}


void EventHandler::handleDrive() {
    int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) {
        rightX += 30;
    }

    chassis.arcade(leftY, rightX, 12.0);
}


void EventHandler::handleAll() {
    EventHandler::handleWings();
    EventHandler::handleCatapult();
    EventHandler::handleIntake();
    EventHandler::updateDisplay();
    EventHandler::handleDrive();
}


